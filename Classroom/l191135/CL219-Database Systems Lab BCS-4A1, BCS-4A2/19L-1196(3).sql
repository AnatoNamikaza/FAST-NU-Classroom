SELECT * FROM Customer
WHERE Customer.city = 'London' OR Customer.city = 'Marseille'

SELECT * FROM Customer
WHERE Customer.Country != 'Germany' OR Customer.Country != 'France' OR Customer.Country != 'Italy'

SELECT COUNT(*) AS 'TotalNumberOfCustomers' FROM Customer
WHERE Customer.Country = 'UK' ;

SELECT Customer.FirstName, Customer.LastName, Customer.Country, Customer.Phone From Customer
WHERE Customer.Phone LIKE '%171%'

SELECT Customer.FirstName, Customer.LastName, Customer.Country, Customer.Phone From Customer
WHERE Customer.Phone like '%7_' OR Customer.Phone LIKe '%8_' AND 
(Customer.Country = 'Germany' OR Customer.Country = 'France' OR Customer.Country = 'UK' OR Customer.Country = 'USA')

SELECT TOP 5* FROM [Order]
ORDER BY  [Order].TotalAmount desc

SELECT * FROM [Order]
WHERE [Order].TotalAmount >= 200 AND [Order].TotalAmount <= 1000 AND ([Order].TotalAmount != 440 OR [Order].TotalAmount!= 670.80)
ORDER BY [Order].TotalAmount DESC

SELECT [Order].OrderNumber, [Order].OrderDate, [Order].TotalAmount, [Order].TotalAmount/7000 AS Achieved, 1-[Order].TotalAmount/7000 AS Unachieved FROM [order]
WHERE  0.5 < TotalAmount/7000
ORDER BY [Order].TotalAmount DESC

SELECT Customer.FirstName + ' ' + Customer.LastName AS FullName, 'Customer' AS PersonType, Customer.Id AS PersonTypeId, Customer.Country AS PersonCountry FROM Customer
WHERE Customer.Country='UK'
UNION SELECT Supplier.ContactName AS FullName, 'Supplier' AS PersonType, Supplier.Id AS PersonTypeId, Supplier.Country AS PersonCountry FROM Supplier
WHERE Supplier.Country='UK'

SELECT * FROM Product
WHERE Product.SupplierId > 10 AND Product.UnitPrice >= 30 AND Product.UnitPrice <= 100

