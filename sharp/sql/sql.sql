CREATE TABLE
	Customers(
	id int Primary key Identify(1,1) ,
	Name nvarchar(20) not null
);

CREATE TABLE
	Orders(
    id int Primary key Identify(1,1) ,
    CustomerId int not null,
    FOREIGN KEY (CustomerId) REFERENCES Customers (id)
);

INSERT INTO
	Customers
VALUES 
	(Max),
	(Pavel),
	(Ivan),
	(Leonid);
	
INSERT INTO 
	Orders
VALUES
	(2)
	(4);


SELECT
	c.Name Customers
FROM
	Customers as c
RIGHT JOIN 
	Orders as o
WHERE 
	o.CustomerId is NULL;

