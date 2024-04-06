--QUESTION#1
CREATE FUNCTION TSum(@pid int)  
RETURNS int   
AS BEGIN declare @s int = (SELECT sum(T1.total_s) FROM (SELECT (product.Price*OrderItem.quantity) AS total_s FROM product JOIN OrderItem
ON product.productId = @pid	and product.productID = OrderItem.productID) AS T1) 
RETURN @s;  
END; 

SELECT dbo.TSum(4)

--QUESTION#2
CREATE FUNCTION ic(@Cid int)
RETURNS TABLE AS RETURN	(SELECT product.productID, product.productName,product.Price, OrderItem.OrderID, OrderItem.quantity FROM product JOIN OrderItem	ON 
product.productID = OrderItem.productID JOIN [Order] ON [Order].OrderID = OrderItem.OrderID where [Order].CustomerID=@Cid)

SELECT * FROM dbo.ic(2) 

--QUESTION#3
SELECT product.productID, product.productName, dbo.TSum(productID) FROM product