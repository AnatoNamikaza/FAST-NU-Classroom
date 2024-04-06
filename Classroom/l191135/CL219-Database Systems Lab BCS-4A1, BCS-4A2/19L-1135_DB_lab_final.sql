--Question#1
create function SurpriseCashBack()
returns table
as return(
select customers.cust_id, customers.cust_name, orders.order_num, table1.total_price, (table1.total_price*0.3) as cashback from
(select orderitems.order_num, sum(orderitems.item_price) as total_price from  orders join orderitems on orders.order_num = orderitems.order_num
join customers on orders.cust_id = customers.cust_id
group by orderitems.order_num
) as table1 join orders
on orders.order_num = table1.order_num
join customers on customers.cust_id = orders.cust_id
where customers.cust_id in ( select orders.cust_id from orders group by orders.cust_id having count(orders.cust_id) >= 3 )
union
select customers.cust_id, customers.cust_name, orders.order_num, table1.total_price, (table1.total_price*0.1) as cashback from
(select orderitems.order_num, sum(orderitems.item_price) as total_price from  orders join orderitems on orders.order_num = orderitems.order_num
join customers on orders.cust_id = customers.cust_id
group by orderitems.order_num
) as table1 join orders
on orders.order_num = table1.order_num
join customers on customers.cust_id = orders.cust_id
where customers.cust_id in ( select orders.cust_id from orders group by orders.cust_id having count(orders.cust_id) < 3 )
)
--execute statement for udf
select * from SurpriseCashBack()

--Question#2
--part(a)
declare @deficted_item NCHAR(10) = 'DTNTR'  

select products.prod_id, products.prod_name from products join vendors on vendors.vend_id = products.vend_id 
where vendors.vend_id = ( select products.vend_id from products where products.prod_id = @deficted_item)

--part(b)
select customers.cust_id, customers.cust_name,orderitems.order_item, count(orderitems.order_item) 
from  orders join orderitems on orders.order_num = orderitems.order_num
join customers on orders.cust_id = customers.cust_id
group by customers.cust_id,customers.cust_name,orderitems.order_item
order by customers.cust_id asc

--part(c)
create view zero_sales_vendors
as (
	select vendors.vend_id, vendors.vend_name from vendors where vendors.vend_id not in 
	(
		select distinct vendors.vend_id from orderitems join products on products.prod_id = orderitems.prod_id
		join vendors on products.vend_id = vendors.vend_id
	)
)

select * from zero_sales_vendors

--part(d)
create view data
as(
select customers.cust_id, vendors.vend_id, count(customers.cust_id) as total_orders
from  orders join orderitems on orders.order_num = orderitems.order_num
join customers on orders.cust_id = customers.cust_id
join products on products.prod_id = orderitems.prod_id
join vendors on products.vend_id = vendors.vend_id
group by customers.cust_id, vendors.vend_id
)

create function best(@id int = 0)
returns table
as return(
select top(1)* from data where vend_id = @id order by total_orders desc
)

select dbo.best(vendors.vend_id) from vendors

--Question#3
--part(a)
create function total_products_in_store(@vend_id int = 0)
returns int
as begin
	declare @total_products int = (select count(products.prod_id) from products group by products.vend_id having products.vend_id = @vend_id )
	return @total_products
end

select vendors.vend_id, dbo.total_products_in_store(vendors.vend_id) from vendors

--part(b)
create view vendor_data
as (
select vendors.vend_id, dbo.total_products_in_store(vendors.vend_id) as total_products,
(select count(distinct table1.prod_id) from (select products.prod_id, vendors.vend_id from
orderitems join products on products.prod_id = orderitems.prod_id
join vendors on products.vend_id = vendors.vend_id) as table1
where  vendors.vend_id = table1.vend_id
) 
as ordered_product,
dbo.total_products_in_store(vendors.vend_id) -(select count(distinct table1.prod_id) from (select products.prod_id, vendors.vend_id from
orderitems join products on products.prod_id = orderitems.prod_id
join vendors on products.vend_id = vendors.vend_id) as table1
where  vendors.vend_id = table1.vend_id
) 
as unsold_products
from  orderitems full join products on products.prod_id = orderitems.prod_id
join vendors on products.vend_id = vendors.vend_id
group by vendors.vend_id
)

select * from vendor_data


--Question#4
create procedure update_quantity
@product_id int = 0,
@quantity int = 0
as begin
transaction savepoint save1

set transactionmode as semantip

update order set quantity=@quantity  where product_id = @product_id 
commit transaction 
end

--Question#5
--part(a)
create trigger UpdatedCustomer
on customers
after update, insert
as begin
	declare @total_changes int = (select count(inserted.cust_id) from inserted )

	select @total_changes as No_of_changes

	select * from inserted 
	select * from deleted 
end

update customers set customers.cust_state = 'OH' where customers.cust_id = 10001

--part(b)
create trigger ValidateOrderItems
on orderitems
instead of insert
as begin

	declare @order_num int = (select inserted.order_num from inserted )
	declare @order_item int = (select inserted.order_item from inserted )
	declare @prod_id NCHAR(10) = (select inserted.prod_id from inserted )
	declare @quantity int = (select inserted.quantity from inserted )
	declare @price MONEY = (select inserted.item_price from inserted )
	
	if @order_num in (select order_num from orders)
	begin
			if @quantity > 0
			begin
				insert into orderitems values
				(
				@order_num,
				@order_item,
				@prod_id,
				@quantity,
				@price
				)
			end
			else 
			begin
				print'Order quantity is zero'
			end
	end
	else 
	begin
		print'Order Number not found'
	end
end



