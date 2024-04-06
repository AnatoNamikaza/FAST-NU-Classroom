CREATE DATABASE db
--/--------------------------- selecting database
USE db
--/--------------------------- creating a schema for students
CREATE TABLE Student( 
	RollNumber varchar(7),
	stdName varchar(30),
	Gender varchar(6),
	PhoneNo varchar(12))
--/--------------------------- creating a schema for Attendence
CREATE TABLE Attendance(
 RollNumber varchar(7),
 Date date,
 Status char(1),
 ClassVenue int not null)

--/--------------------------- creating a schema for ClassVenue
CREATE TABLE ClassVenue(
ID int,
Building varchar(10),
RoomNum int,
TeacherName varchar(30))
--/--------------------------- creating a schema for Teacher

CREATE TABLE Teacher(
TeacherName varchar(30),
Designation varchar(30),
Department varchar(30))
--/--------------------------- Inserting tuples/recordes in order
INSERT INTO Student
VALUES ('L164123' ,'Ali Ahmad', 'Male' ,'0333-3333333'),
('L164124', 'Rafia Ahmed' ,'Female' ,'0333-3456789'), 
('L164125', 'Basit Junaid', 'Male', '0345-3243567')
GO
--/--GO for batch processing
--/--------------------------- retreivel
SELECT* FROM Student 
--/---------------------------
INSERT INTO Attendance
VALUES ('L164123' ,'2-22-2016', 'P' ,2),
('L164124', '2-23-2016' ,'A' ,1), 
('L164125', '3-4-2016', 'P', 2)
GO
--/---------------------------
SELECT* FROM Attendance

INSERT INTO ClassVenue
VALUES 
(1 ,'CS', 2 ,'Sarim Baig'),
(2, 'Civil' ,7 ,'Bismillah Jan')
GO
--/---------------------------
SELECT* FROM ClassVenue
--/---------------------------
INSERT INTO Teacher
VALUES
('Sarim Baig','Assistant Prof.','Computer Science'),
('Bismillah Jan','Lecturer','Civil Eng.'),
('Kashif zafar','Professor','Electrical Eng.')
GO
--/---------------------------
SELECT* FROM Teacher
--/--------------------------- Modifying Schema
ALTER TABLE Student ALTER COLUMN [RollNumber] varchar(10) not null 
ALTER TABLE Student ADD CONSTRAINT PrimaryKey PRIMARY KEY (RollNumber)

--/---------------------------
ALTER TABLE Attendance ALTER COLUMN [RollNumber] varchar(10) not null 
ALTER TABLE Attendance ALTER COLUMN [Date] date not null
ALTER TABLE Attendance ADD CONSTRAINT PrimaryKey2 PRIMARY KEY (RollNumber,[Date])
--/---------------------------
ALTER TABLE ClassVenue ALTER COLUMN [Building] varchar(10) not null
ALTER TABLE ClassVenue ALTER COLUMN [RoomNum] int not null
ALTER TABLE ClassVenue ALTER COLUMN [ID] int not null
ALTER TABLE ClassVenue ALTER COLUMN [TeacherName] varchar(50) not null
ALTER TABLE ClassVenue ADD CONSTRAINT PrimaryKey3 PRIMARY KEY (ID)

--/---------------------------
ALTER TABLE Teacher ALTER COLUMN [TeacherName] varchar(50) not null
ALTER TABLE Teacher ADD CONSTRAINT PrimaryKey4 PRIMARY KEY (TeacherName)

--/---------------------------
ALTER TABLE Attendance ADD CONSTRAINT foreignKey1 FOREIGN KEY (RollNumber) REFERENCES Student(RollNumber)
--/---------------------------
ALTER TABLE ClassVenue ADD CONSTRAINT foreignKey2 FOREIGN KEY (TeacherName) REFERENCES Teacher(TeacherName)
--/---------------------------

SELECT* FROM Teacher
SELECT* FROM Student
SELECT* FROM ClassVenue
SELECT* FROM Attendance
--/---------------------------
ALTER TABLE Student ADD warningCount int
ALTER TABLE Student DROP COLUMN PhoneNo
--/---------------------------

INSERT INTO Student
VALUES('L162334', 'Fozan Shahid',' Male', 3.2)

--though valid but 3.2 is truncated to 3

SELECT* FROM Student
--/--------------------------- updating the already inserted record
Update Teacher set TeacherName= 'Dr. Kashif Zafar' WHERE TeacherName= 'Kashif zafar'
--/--it is valid

DELETE FROM Student WHERE RollNumber='L162334' 
--it is valid but roll no does not exist there

DELETE FROM Student WHERE RollNumber='L164123' 
--/--Not valid as there exists in attendance table too

DELETE FROM Attendance WHERE RollNumber='L164124'
--/--it is valid

ALTER TABLE Teacher ADD CONSTRAINT uniqueCONSTRAINT_TeacherName Unique (TeacherName)
ALTER TABLE Student ADD CONSTRAINT gender_MF check (Gender='Male' or Gender='Female')
ALTER TABLE Attendance ADD CONSTRAINT A_PA check (Status='A' or Status='P')
