--	Roll no: 19L-1135
--	Q-1 _______________________________________________________________________________________________

--create database University_Database;

--USE University_Database;

/*
create table Student (
	RollNum char(8),
	Name varchar(30),
	Gender varchar(6),
	Phone char(12)
);

create table Attendance (
	RollNum char(8),
	Date varchar(10),
	Status char(1),
	ClassVenue integer
);

create table ClassVenue (
	ID integer,
	Building varchar(10),
	RoomNum integer,
	Teacher varchar(30)
);

create table Teacher (
	Name varchar(30),
	Designation varchar(30),
	Department varchar(30)
);

INSERT INTO [Student] ([RollNum], [Name], [Gender], [Phone])
VALUES	('L164123', 'Ali Ahmad', 'Male', '0333-3333333'),
	('L164124', 'Rafia Ahmed', 'Female', '0333-3456789'),
	('L164125', 'Basit Junaid', 'Male', '0345-3243567')
GO

INSERT INTO [Attendance] ([RollNum], [Date], [Status], [ClassVenue])
VALUES	('L164123', '2-22-2016', 'P', 2),
	('L164124', '2-23-2016', 'A', 1),
	('L164125', '3-4-2016', 'P', 2)
GO

INSERT INTO [ClassVenue] ([ID], [Building], [RoomNum], [Teacher])
VALUES	(1, 'CS', 2, 'Sarim Baig'),
	(2, 'Civil', 7, 'Bismillah Jan')
GO

INSERT INTO [Teacher] ([Name], [Designation], [Department])
VALUES	('Sarim Baig', 'Assistant Prof.', 'Computer Science'),
	('Bismillah Jan', 'Lecturer', 'Civil Eng.'),
	('Kashif zafar', 'Professor', 'Electrical Eng.')
GO
-- _______________________________________________________________________________________________




-- Q-2 _______________________________________________________________________________________________
/*
alter table Student add constraint PK1 primary key (RollNum)
alter table Attendance add constraint PK2 primary key (RollNum)
alter table ClassVenue add constraint PK3 primary key (ID)
alter table Teacher add constraint PK4 primary key (Name)
-- _______________________________________________________________________________________________





-- Q-3 _______________________________________________________________________________________________
/*
alter table Attendance
add constraint FK1 foreign key (RollNum) references Student(RollNum) on update cascade on delete no action


alter table Attendance
add constraint FK2
foreign key (ClassVenue) references ClassVenue(ID) on update cascade on delete set null

alter table ClassVenue
add constraint FK3
foreign key (Teacher) references Teacher(Name) on update cascade on delete set null
-- _______________________________________________________________________________________________




-- Q-4 _______________________________________________________________________________________________
/*
alter table Student add Warning integer
alter table Student drop column [Phone]
-- _______________________________________________________________________________________________




-- Q-5 _______________________________________________________________________________________________
--	Part-1
/*
INSERT INTO [Student] ([RollNum], [Name], [Gender], [Warning_Count])
VALUES ('L162334', 'Fozan Shahid', 'Male', 3.2)
GO
-- This is a valid query

--	Part-2
/*
INSERT INTO [ClassVenue] ([ID], [Building], [RoomNum], [Teacher])
VALUES	(3, 'CS', 5, 'Ali')
GO
-- This is an invalid query. To correct it, the following methods can be used:
-- 1. Add a teacher that already exists in teacher table.
-- 2. First add the new teacher in teacher table and then use this query for that new teacher's name.

--	Part-3
/*
update Teacher
set Name='Dr. Kashif Zafar'
where Name='Kashif zafar'
-- This is a valid query

--	Part-4
/*
delete from Student
where RollNum='L162334'
-- This is a valid query

--	Part-5
/*
delete from Student
where RollNum='L164123'
-- This is an invalid query. To correct it, the following method can be used:
-- delete all rows having RollNum='L164123' in Attendance table and then execute this query.

--	Part-6
/*
delete from Attendance
where RollNum='L164124' and Status='A'
-- This is a valid query
-- _______________________________________________________________________________________________




-- Q-6 _______________________________________________________________________________________________
/*
alter table Teacher add constraint Unix1 unique (Name)

alter table Student add check (Gender='Male' OR Gender='Female')

alter table Attendance add check(Status='A' OR Status='P')
-- _______________________________________________________________________________________________