use master
go
drop database final2021_l191196
create database final2021_l191196
use final2021_l191196

/*
Create customers table
*/

CREATE TABLE [customers]
(
  cust_id      INT        NOT NULL IDENTITY(1,1),
  cust_name    NCHAR(50)  NOT NULL ,
  cust_address NCHAR(50)  NULL ,
  cust_city    NCHAR(50)  NULL ,
  cust_state   NCHAR(5)   NULL ,
  cust_zip     NCHAR(10)  NULL ,
  cust_country NCHAR(50)  NULL ,
  cust_contact NCHAR(50)  NULL ,
  cust_email   NCHAR(255) NULL
);
ALTER TABLE customers
ADD CONSTRAINT pk_customers PRIMARY KEY (cust_id);


/*
Create orderitems table
*/
CREATE TABLE orderitems
(
  order_num  INT       NOT NULL ,
  order_item INT       NOT NULL ,
  prod_id    NCHAR(10) NOT NULL ,
  quantity   INT       NOT NULL ,
  item_price MONEY     NOT NULL 
);
ALTER TABLE orderitems
ADD CONSTRAINT pk_orderitems PRIMARY KEY (order_num, order_item);


/*
Create orders table
*/
CREATE TABLE orders
(
  order_num  INT      NOT NULL IDENTITY(1,1),
  order_date DATETIME NOT NULL ,
  cust_id    INT      NOT NULL
);
ALTER TABLE orders
ADD CONSTRAINT pk_orders PRIMARY KEY (order_num);


/*
Create products table
*/
CREATE TABLE products
(
  prod_id    NCHAR(10)  NOT NULL,
  vend_id    INT        NOT NULL ,
  prod_name  NCHAR(255) NOT NULL ,
  prod_price MONEY      NOT NULL ,
  prod_desc  NTEXT      NULL
);
ALTER TABLE products
ADD CONSTRAINT pk_products PRIMARY KEY (prod_id);


/*
Create vendors table
*/
CREATE TABLE vendors
(
  vend_id      INT       NOT NULL identity(1,1),
  vend_name    NCHAR(50) NOT NULL ,
  vend_address NCHAR(50) NULL ,
  vend_city    NCHAR(50) NULL ,
  vend_state   NCHAR(5)  NULL ,
  vend_zip     NCHAR(10) NULL ,
  vend_country NCHAR(50) NULL
);
ALTER TABLE vendors
ADD CONSTRAINT pk_vendors PRIMARY KEY (vend_id);


/*
Create productnotes table
*/
CREATE TABLE productnotes
(
  note_id    INT            NOT NULL IDENTITY(1,1),
  prod_id    NCHAR(10)      NOT NULL,
  note_date  DATETIME       NOT NULL,
  note_text  NTEXT          NULL
);
ALTER TABLE productnotes
ADD CONSTRAINT pk_productnotes PRIMARY KEY (note_id);


/*
Define foreign keys
*/
ALTER TABLE orderitems ADD CONSTRAINT fk_orderitems_orders FOREIGN KEY (order_num) REFERENCES orders (order_num);
ALTER TABLE orderitems ADD CONSTRAINT fk_orderitems_products FOREIGN KEY (prod_id) REFERENCES products (prod_id);
ALTER TABLE orders ADD CONSTRAINT fk_orders_customers FOREIGN KEY (cust_id) REFERENCES customers (cust_id);
ALTER TABLE products ADD CONSTRAINT fk_products_vendors FOREIGN KEY (vend_id) REFERENCES vendors (vend_id);
ALTER TABLE productnotes ADD CONSTRAINT fk_productnotes_products FOREIGN KEY (prod_id) REFERENCES products (prod_id);


/* 
		Data Population 		
*/

/* Populate customers table */
SET IDENTITY_INSERT customers ON;
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10001, 'Coyote Inc.', '200 Maple Lane', 'Detroit', 'MI', '44444', 'USA', 'Y Lee', 'ylee@coyote.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact)
VALUES(10002, 'Mouse House', '333 Fromage Lane', 'Columbus', 'OH', '43333', 'USA', 'Jerry Mouse');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10003, 'Wascals', '1 Sunny Place', 'Muncie', 'IN', '42222', 'USA', 'Jim Jones', 'rabbit@wascally.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10004, 'Yosemite Place', '829 Riverside Drive', 'Phoenix', 'AZ', '88888', 'USA', 'Y Sam', 'sam@yosemite.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact)
VALUES(10005, 'E Fudd', '4545 53rd Street', 'Chicago', 'IL', '54545', 'USA', 'E Fudd');
SET IDENTITY_INSERT customers OFF;


/* Populate vendors table */
SET IDENTITY_INSERT vendors ON;
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1001,'Anvils R Us','123 Main Street','Southfield','MI','48075', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1002,'LT Supplies','500 Park Street','Anytown','OH','44333', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1003,'ACME','555 High Street','Los Angeles','CA','90046', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1004,'Furball Inc.','1000 5th Avenue','New York','NY','11111', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1005,'Jet Set','42 Galaxy Road','London', NULL,'N16 6PS', 'England');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1006,'Jouets Et Ours','1 Rue Amusement','Paris', NULL,'45678', 'France');
SET IDENTITY_INSERT vendors OFF;


/* Populate products table */
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV01', 1001, '.5 ton anvil', 5.99, '.5 ton anvil, black, complete with handy hook');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV02', 1001, '1 ton anvil', 9.99, '1 ton anvil, black, complete with handy hook and carrying case');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV03', 1001, '2 ton anvil', 14.99, '2 ton anvil, black, complete with handy hook and carrying case');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('OL1', 1002, 'Oil can', 8.99, 'Oil can, red');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FU1', 1002, 'Fuses', 3.42, '1 dozen, extra long');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('SLING', 1003, 'Sling', 4.49, 'Sling, one size fits all');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('TNT1', 1003, 'TNT (1 stick)', 2.50, 'TNT, red, single stick');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('TNT2', 1003, 'TNT (5 sticks)', 10, 'TNT, red, pack of 10 sticks');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FB', 1003, 'Bird seed', 10, 'Large bag (suitable for road runners)');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FC', 1003, 'Carrots', 2.50, 'Carrots (rabbit hunting season only)');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('SAFE', 1003, 'Safe', 50, 'Safe with combination lock');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('DTNTR', 1003, 'Detonator', 13, 'Detonator (plunger powered), fuses not included');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('JP1000', 1005, 'JetPack 1000', 35, 'JetPack 1000, intended for single use');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('JP2000', 1005, 'JetPack 2000', 55, 'JetPack 2000, multi-use');



/* Populate orders table */
SET IDENTITY_INSERT orders ON;
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20005, '2005-09-01', 10001);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20006, '2005-09-12', 10003);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20007, '2005-09-30', 10004);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20008, '2005-10-03', 10005);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20009, '2005-10-08', 10001);
SET IDENTITY_INSERT orders OFF;


/* Populate orderitems table */
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 1, 'ANV01', 10, 5.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 2, 'ANV02', 3, 9.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 3, 'TNT2', 5, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 4, 'FB', 1, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20006, 1, 'JP2000', 1, 55);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20007, 1, 'TNT2', 100, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20008, 1, 'FC', 50, 2.50);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 1, 'FB', 1, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 2, 'OL1', 1, 8.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 3, 'SLING', 1, 4.49);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 4, 'ANV03', 1, 14.99);

/* Populate productnotes table */
SET IDENTITY_INSERT productnotes ON;
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(101, 'TNT2', '2005-08-17',
'Customer complaint:
Sticks not individually wrapped, too easy to mistakenly detonate all at once.
Recommend individual wrapping.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(102, 'OL1', '2005-08-18',
'Can shipped full, refills not available.
Need to order new can if refill needed.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(103, 'SAFE', '2005-08-18',
'Safe is combination locked, combination not provided with safe.
This is rarely a problem as safes are typically blown up or dropped by customers.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(104, 'FC', '2005-08-19',
'Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(105, 'TNT2', '2005-08-20',
'Included fuses are short and have been known to detonate too quickly for some customers.
Longer fuses are available (item FU1) and should be recommended.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(106, 'TNT2', '2005-08-22',
'Matches not included, recommend purchase of matches or detonator (item DTNTR).'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(107, 'SAFE', '2005-08-23',
'Please note that no returns will be accepted if safe opened using explosives.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(108, 'ANV01', '2005-08-25',
'Multiple customer returns, anvils failing to drop fast enough or falling backwards on purchaser. Recommend that customer considers using heavier anvils.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(109, 'ANV03', '2005-09-01',
'Item is extremely heavy. Designed for dropping, not recommended for use with slings, ropes, pulleys, or tightropes.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(110, 'FC', '2005-09-01',
'Customer complaint: rabbit has been able to detect trap, food apparently less effective now.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(111, 'SLING', '2005-09-02',
'Shipped unassembled, requires common tools (including oversized hammer).'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(112, 'SAFE', '2005-09-02',
'Customer complaint:
Circular hole in safe floor can apparently be easily cut with handsaw.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(113, 'ANV01', '2005-09-05',
'Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead.'
);
INSERT INTO productnotes(note_id, prod_id, note_date, note_text)
VALUES(114, 'SAFE', '2005-09-07',
'Call from individual trapped in safe plummeting to the ground, suggests an escape hatch be added.
Comment forwarded to vendor.'
);
SET IDENTITY_INSERT productnotes OFF;

go

select * from customers
select * from orderitems
select * from orders
select * from products
select * from vendors
select * from productnotes

--Q(1)1
select * from products as p
inner join vendors as v
on p.vend_id = v.vend_id
where prod_id = 'DTNTR'

--Q1(2)
--customerid name,unique items
select *from [customers] as c
inner join orders as o
on o.cust_id = o.cust_id

select * from orderitems as oi
inner join products as p
on oi.prod_id = p.prod_id

--Q1(3)
create view vw_neversold
as
select * from
(products as p left join orderitems as o on p.prod_id = o.prod_id)

--Q1(4)
select * from customers as c
inner join orders as o
on c.cust_id = o.cust_id 

-- Q2
-- part 1

create function vendor_products(@vender_id int)
returns int
as
begin
declare @returnvalue int,
select @returnvalue = count(*)
from customers as c
inner join orders as o
on c.cust_id = o.cust_id
(select * ) from prodcuts as p inner join orderitems as it
on it.prod_id=p.prod_id

return @returnvalue
end


-- Q2-part 2
create view vw_vendor_detail
as
select vend_id, vend_name from vendors
select vend_id, count(*) products
group by vend_id
-- all products which are in orderitems
select * from products as p
left join orderitems as oi
on oi.prod_id=p.prod_id
-- all products which were never sold
select * from products as p
right join orderitems as oi
on oi.prod_id=p.prod_id

--Q3

create function calculateCashBack(@no_orders, @total_amount int)
returns int
as
begin
declare @returnvalue int,
if(@no_orders > 3)
begin
select @returnvalue = 30*@total_amount/100.0
end
else
begin
select @returnvalue = 10*@total_amount/100.0
end
return @returnvalue
end

create procedure SurpriseCashBack
as
begin
select [customers].cust_id, [customer].cust_name, price, select * from calculateCashBack(list.orders,price)
select list.item_price * list.quantity as price
(select * from orders join orderitems on orders.order_num=orderitems.order_num) as list
end

--Q4 part i
create trigger validateOrderItems
for orderitems on insert
if(orderitems.quantity > 0)
begin
orderitems.quantity = orderitems.quantity
end
else
begin
print('quantity should be greater than 0')
end

--Q4 part ii
create trigger UpdatedCustomer
for [customers] on update
select * from [customers] 
select count(*) [inserted]

-- Q5
create procedure quantity_updater(@customer_id int,@cus_name varchar(30),@cust_address varchar(30),@cust_city varchar(20),@cust_state varchar(30),@cust_zip int,@cust_country varchar(30),cust_contact varchar(20),@cust_email varchar(20)))
as begin
begin transaction
	save transaction savepoint;
		INSERT quantity_update(@customer_id,@cus_name,@cust_address,@cust_city,@cust_state,@cust_zip,@cust_country,cust_contact,@cust_email)
		if @@trancount > 0
		begin
			PRINT 'please enter the data carefully'
				rollback transaction savepoint;
		end
end
	commit transaction
end