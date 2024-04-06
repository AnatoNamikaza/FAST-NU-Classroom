--QUESTION#1
CREATE TRIGGER SAFE_sTD
ON Students INSTEAD of DELETE
AS BEGIN PRINT'You don’t have the permission to DELETE the student'
END

DELETE FROM Students WHERE warningcount = 1

--QUESTION#2
CREATE TRIGGER RES_cRS
ON Courses
INSTEAD of Insert
AS BEGIN PRINT'You don’t have the permission to Insert a new Course'
END

INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (50, N'Basic', NULL,5)

--QUESTION#3
CREATE TABLE notice_sys(NotIFictionID int, StudentID int,NotIFication Varchar(20))
CREATE TRIGGER reg_course
on Registration INSTEAD of INSERT AS BEGIN
DECLARE @rollno int, @Course int, @PCourse int, @cleared int, @GPA int,
@Semester varchar(30),@Section varchar(2)
SELECT @rollno = inserted.RollNumber, @Course = CourseID, @GPA = GPA, @Semester=Semester,@Section=Section FROM inserted 
SELECT @PCourse = PrerequiteCourseID FROM Courses WHERE CourseID = @Course
SELECT @cleared = GPA FROM Registration WHERE CourseID=@PCourse and RollNumber=@rollno
IF  (@GPA<2) or (@cleared<2)
BEGIN
INSERT INTO notice_sys VALUES (1,@rollno,N'Not Successful')
END
ELSE
BEGIN
INSERT [dbo].[Registration] VALUES (@Semester,@rollno, @Course, @Section,@GPA)
INSERT INTO notice_sys VALUES (1,@rollno,N'Successful')
END
END

INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID],[Section],GPA) VALUES (N'Spring2017', N'4', 40, N'D',7)

SELECT * FROM notice_sys

----QUESTION#4
CREATE TRIGGER ENR_STD
on Registration INSTEAD of insert
AS BEGIN DECLARE @rollno int
SELECT @rollno = RollNumber FROM inserted 
IF @rollno in (SELECT ChallanForm.RollNumber FROM ChallanForm 
WHERE ChallanForm.Status='PENDing' and ChallanForm.TotalDues>=20000)
BEGIN
PRINT'Due not cleared'
END
END

INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Spring2017', N'4', 40, N'D',1)

--QUESTION#5
CREATE TRIGGER REM_scRS
on Courses_Semester INSTEAD of DELETE
AS BEGIN DECLARE @seats int
SELECT @seats = AvailableSeats FROM DELETEd
IF(@seats < 10)
BEGIN
PRINT'Not Possible'
END
END

DELETE FROM Courses_Semester WHERE InstructorId = 100 and AvailableSeats = 9

--QUESTION#6
CREATE TRIGGER SAFE_LOCK 
ON DATABASE FOR DROP_TABLE, ALTER_TABLE 
AS BEGIN PRINT 'You must disable TRIGGER "SAFE_LOCK" to DROP or ALTER a TABLE in database.' 
ROLLBACK
END

ALTER TABLE Instructors
ADD Stars int;
SELECT*FROM Instructors
