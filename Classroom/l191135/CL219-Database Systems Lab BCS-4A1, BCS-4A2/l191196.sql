use master
go
IF DB_ID('ECommerce') IS NOT NULL
drop  database ECommerce
go 
Create database ECommerce
go 
use ECommerce
go


Create Table Manufacturers
(
  manufacturerId int primary key,
  manufacturerName nvarchar(100)
)

Insert into Manufacturers values (1, 'GlaxoSmithKline')
Insert into Manufacturers values (2, 'nestle')
Insert into Manufacturers values (3, 'K&N''s')
Insert into Manufacturers values (4, 'Honor')
Insert into Manufacturers values (5, 'Dell')
Insert into Manufacturers values (6, 'olpers')

Create Table Products(

  productId int primary key,
  productName nvarchar(50),
  productDetails nvarchar(100),
  price float,
  quantityInStore int,
  manufacturerId int foreign key references Manufacturers(manufacturerId),
)

Insert into Products values (1, 'DELL Inspiron Laptop 5770', 'Core i5, 8GB RAM, 500 SD', 85000, 10, 5)
Insert into Products values (2, 'Honor 9x Mobile', 'Snapdragon processor, 6GB Ram, 128GB Internal Space', 35000, 5, 4)
Insert into Products values (3, 'Chicken Fillet K&Ns', '5 pieces', 650, 30, 3)
Insert into Products values (4, 'nestle water','half liter', 30, 100, 2)
Insert into Products values (5, 'nestle fruit juice','mango flavor- 1 liter', 130, 1000, 2)
Insert into Products values (6, 'paracetamol','100mg', 30, 150, 1)
Insert into Products values (7, 'olpers milk', '1 kg', 140, 100, 6)


Create Table Users
(
  userId int primary key,
  userName nvarchar(100),
  address nvarchar(100),
  dateOfBirth date
)


insert into Users values (1,'ali','iqbal Town Lahore','2000-5-20')
insert into Users values (3,'hafeez','defence phase 7 karachi','1997-6-19')
insert into Users values (2, 'umer', 'johan town', '1998-01-04')

Create Table Orders(

  orderId int primary key,
  userId int foreign key references Users (userId),
  datePlaced date,
  orderStatus varchar(20),
  
  CHECK (orderStatus in ('delivered', 'in-progress', 'cancelled'))
)


insert into Orders values (1 ,3 ,'2020-01-10','delivered')
Insert into Orders values (2, 2, '2020-07-16', 'in-progress')
Insert into Orders values (3, 1, '2017-05-05', 'delivered')
Insert into Orders values (4, 1, '2018-01-01', 'cancelled')
insert into Orders values (5 ,3 ,'2019-5-20','delivered')
Insert into Orders values (6, 1, '2020-07-16', 'in-progress')

Create Table OrderDetails
(
  orderId int foreign key references Orders (orderId),
  productId int foreign key references Products (productId),
  quantityRequired int,
  primary key (orderId, productId)
)


insert into OrderDetails values (1 , 2, 10 )
insert into OrderDetails values (1 , 3, 3)
insert into OrderDetails values (1 , 6 , 10 )
Insert into OrderDetails values (2, 1, 1)
Insert into OrderDetails values (2, 2, 7)
Insert into OrderDetails values (2, 3, 5)
Insert into OrderDetails values (3, 5, 1)
insert into OrderDetails values (4, 1, 1)
insert into OrderDetails values (4, 3, 1)
insert into OrderDetails values (5, 1 , 1 )
insert into OrderDetails values (5, 5, 35 )
insert into OrderDetails values (5, 4, 1 )
Insert into OrderDetails values (5, 7, 2)
Insert into OrderDetails values (6, 5, 1)


--drop view purchaser
--Q1-----------------------------

create view purchaser as
select Users.userId, Users.userName from Users
join 
Orders on Orders.userId = Users.userId
join 
OrderDetails on OrderDetails.orderId=Orders.orderId 
group by Users.userId, Users.userName
-- at least one > 1
having count (distinct OrderDetails.productId) > 1
go

--Q2-------------------------------
-- solve it at the end 

--Q3-------------------------------
-- solve it at the end
--Q4-------------------------------
Create procedure returnProductQuantity
@in_orderId int = 0,
@in_productId int = 0,
@quantity_returned int = 0,
@money_refund int output
as begin

	declare @status varchar(20) = (select orderstatus from Orders where orderId = @in_orderId )

if @in_orderId in (select Orders.orderId from Orders)
	begin
		if @status != 'cancelled'
		begin
			if @in_productId in (select Products.productId from Products)
			begin
				if @in_productId in (select orderdetails.productId from OrderDetails where orderId = @in_orderId)
				begin
					if @quantity_returned <= (select orderdetails.quantityRequired from OrderDetails where orderId = @in_orderId and productId = @in_productId)
					begin
						if @status = 'delivered'
						begin
							update OrderDetails set OrderDetails.quantityRequired -= @quantity_returned where orderId = @in_orderId and productId = @in_productId
							update Products set products.quantityInStore += @quantity_returned where productId = @in_productId
							
							set @money_refund = @quantity_returned * (select price from Products where productId = @in_productId)
							Print cast(@money_refund as varchar(20))+'amount refunded'
						end
						else if @status = 'in-progress'
						begin
							update OrderDetails set OrderDetails.quantityRequired -= @quantity_returned where orderId = @in_orderId and productId = @in_productId
							set @money_refund = 0
						end
					end
					else
						Print 'Invalid Quantity'
				end
				else 
					Print 'Product Id not Found in the Given Order'
			end
			else
				Print 'Invalid Product Id'
		end
		else
			Print 'No Product can be returned against cancelled orders'
	end
	else
	Print 'Invalid order id.'
end

declare @ans int = 0
execute returnProductQuantity
@in_orderId = 1,
@in_productId = 2,
@quantity_returned = 2,
@money_refund = @ans output
--select @ans as Refunded
go


select * from Products 
select * from orders 
select * from OrderDetails
--Q5-------------------------------
create trigger delete_checker
on Orderdetails
instead of delete
as begin
	declare @o_id int = (select orderId from deleted),
	@p_id int = (select productId from deleted)

	declare @status varchar(20) = (select orderstatus from Orders where orderId = @o_id )
	
	if @o_id in (select Orders.orderId from Orders)
	begin
		if @p_id in (select Products.productId from Products)
		begin
			if @status in ('delivered','in-progress','cancelled')
			begin
				if @status != 'delivered'
				begin
					delete from OrderDetails where orderId = @o_id
					and productId = @p_id
				end
			end
			else
				Print 'Invalid status'
		end
		else
			Print 'Invalid Product id.'
	end
	else
	Print 'Invalid order id.'
end

go

