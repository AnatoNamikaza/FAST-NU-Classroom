use master
go
drop  database Neon1
go 
Create database Neon1
go 
use Neon1

go
create table Students
(RollNo varchar(7) primary key
,Name varchar(30)
,WarningCount int
,Department varchar(15)
)
GO
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'1', N'Ali', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'2', N'Bilal', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'3', N'Ayesha', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'4', N'Ahmed', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'5', N'Sara', 0, N'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'6', N'Salman', 1, N'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'7', N'Zainab', 2, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'8', N'Danial', 1, N'CS')

go
create table Courses
(
CourseID int primary key,
CourseName varchar(40),
PrerequiteCourseID int,
CreditHours int
) 
GO
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (10, N'Database Systems', 20, 3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (20, N'Data Structures', 30,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (30, N'Programing', NULL,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (40, N'Basic Electronics', NULL,3)
go

go
Create table Instructors 
(
InstructorID int Primary key,
Name varchar(30),
Department varchar(7) ,
)
GO
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (100, N'Ishaq Raza', N'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (200, N'Zareen Alamgir', N'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (300, N'Saima Zafar', N'EE')
go
Create table Semester
(
Semester varchar(15) Primary key,
[Status] varchar(10),
)
GO
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Fall2016', N'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Spring2016', N'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Spring2017', N'InProgress')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Summer2016', N'Cancelled')
go
Create table Courses_Semester
(
InstructorID int Foreign key References Instructors(InstructorID),
CourseID int Foreign key References Courses(CourseID),
Semester varchar(15) Foreign key References Semester(Semester), 
Section varchar(1) ,
AvailableSeats int,
Department varchar(2)
)
GO
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2017', N'D', 45, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2017', N'C', 0, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (100, 10, N'Spring2017', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, N'Spring2017', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, N'Spring2016', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2016', N'A', 0, N'CS')

go



create table Registration
(
Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
CourseID int Foreign key References Courses(CourseID), 
Section varchar(1),
GPA float
)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'1', 20, N'A', 3.3)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'2', 20, N'B', 4)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Spring2016', N'1', 30, N'A', 1.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'6', 40, N'D',0.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Spring2017', N'6', 40, N'D',1)


go

Create table ChallanForm
(Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
TotalDues int,
[Status] varchar(10)
)
GO
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'1', 100000, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'2', 13333, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'3', 5000, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'4', 20000, N'Pending')


select * from Students
select * from Courses
select * from Instructors
select * from Registration
select * from Semester
select * from Courses_Semester
select * from ChallanForm

--Question-1
create trigger warning_counts
on Semester
after	Update,
Insert
as begin
	if 'Complete' = (select inserted.Status from inserted) 
	begin
		declare @gs varchar(15) 
		= (select inserted.Semester from inserted)
		
		update Students
		set Students.WarningCount = Students.WarningCount + 1
		where Students.RollNo in(
		select	RollNumber from Registration join Courses 
		on		Registration.CourseID = Courses.CourseID
		where	Registration.Semester = @gs
		group by RollNumber
		Having count(Registration.CourseID) >= 2
		and	sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) < 2)
	end
end


insert into Semester values ('Spring2017','Complete')

--Question-2
alter table Semester
add 
avg_gpa			float NULL,
fail_s			int NULL,
pass_s			int NULL,
gold_medalist	int NULL,
silver_medalist	int NULL,
bronze_medalist int NULL

create trigger warning_counts
on Semester
after	Update,
		Insert
as begin
	if 'Complete' = (select inserted.Status from inserted) 
	begin
		declare @gs varchar(15) = (select Semester from inserted)
	
		update Students
		set Students.WarningCount = Students.WarningCount + 1
		where Students.RollNo in(
		select	RollNumber from Registration join Courses 
		on		Registration.CourseID = Courses.CourseID
		where	Registration.Semester = @gs
		group by RollNumber
		Having count(Registration.CourseID) >= 2
		and	sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) < 2)

		declare @f_s int =	(	select count(t1.num) from (
															select Registration.RollNumber as num
															from Registration join Courses 
															on	Registration.CourseID = Courses.CourseID
															where Registration.Semester = @gs
															group by RollNumber
															having count(Registration.CourseID) >= 2
															and sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) < 2
														) as t1 ),
		@p_s int = (			select count(t2.num) from	(
															select Registration.RollNumber as num
															from Registration join Courses 
															on	Registration.CourseID = Courses.CourseID
															where Registration.Semester = @gs
															group by RollNumber
															having count(Registration.CourseID) >= 2
															and sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) >= 2
														) as t2 ),
		@g_stds int = (			select count(t3.num) from	(
															select Registration.RollNumber as num
															from Registration join Courses 
															on	Registration.CourseID = Courses.CourseID
															where Registration.Semester = @gs
															group by RollNumber
															having count(Registration.CourseID) >= 2
															and sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) >= 3.9
														) as t3 ),
		@s_stds int = (			select count(t4.num) from	(
															select Registration.RollNumber as num
															from Registration join Courses 
															on	Registration.CourseID = Courses.CourseID
															where Registration.Semester = @gs
															group by RollNumber
															having count(Registration.CourseID) >= 2
															and sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) between 3.5 And 3.8
														) as t4 ),
		@b_stds int = (			select count(t5.num) from	(
															select Registration.RollNumber as num
															from Registration join Courses 
															on	Registration.CourseID = Courses.CourseID
															where Registration.Semester = @gs
															group by RollNumber
															having count(Registration.CourseID) >= 2
															and sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) between 3.0 And 3.4
														) as t5 ),
		@avg_gpa float = (		(	select sum (t6.cgpas) from (
														select	sum(Courses.CreditHours * Registration.GPA)/sum (Courses.CreditHours) as cgpas
														from Registration join Courses 
														on	Registration.CourseID = Courses.CourseID
														where Registration.Semester = @gs
														group by RollNumber
														having count(Registration.CourseID) >= 2
													) as t6	)
			/					(	select count(t7.num) from (
														select Registration.RollNumber as num
														From Registration join Courses 
														on	Registration.CourseID = Courses.CourseID
														where Registration.Semester = @gs
														group by RollNumber
														Having Count(Registration.CourseID) >= 2
													) as t7 ) 
						)

		update Semester
		set Semester.avg_gpa = @avg_gpa,
		Semester.fail_s = @f_s,
		Semester.pass_s = @p_s,
		Semester.gold_medalist = @g_stds,
		Semester.silver_medalist = @s_stds,
		Semester.bronze_medalist = @b_stds
		where Semester.Semester = @gs
	end
end

insert into Semester values ('Spring2017','Complete', NULL, NULL, NULL, NULL, NULL, NULL)

--Question-3
create Procedure Register
@r_no		int,
@c_id		int,
@semester	varchar(20)
as begin 
			declare @v_found int = 0, @prereq_clr int = 0

			if (select Courses.PrerequiteCourseID from Courses where CourseID = @c_id ) Is not NULL
			begin
			set @prereq_clr = (select Courses.PrerequiteCourseID from Courses where CourseID = @c_id )
			end
	
			if @prereq_clr > 0
			begin
			if (select Registration.GPA from Registration where CourseID = @prereq_clr and RollNumber = @r_no ) < 2 
			begin
				set @v_found +=1
				Print 'student has not completed prerequisite of the course in which he wants to register.'
			end
			end

			if (select Students.WarningCount from Students where Students.RollNo = @r_no) > 0 
			begin
			set @v_found +=1
			Print 'Warning count of student is not zero.'
			end

			if ( select Top(1) Courses_Semester.Section from Courses_Semester where Courses_Semester.CourseID = @c_id and Courses_Semester.AvailableSeats > 0) is Null
			begin
			set @v_found +=1
			Print 'seat are not available in any section of that course.'
			end

			if ( select Distinct Courses_Semester.Department from Courses_Semester where Courses_Semester.CourseID = @c_id and Courses_Semester.AvailableSeats > 0) 
			!= ( select Students.Department from Students where Students.RollNo = @r_no) 
			begin
			set @v_found +=1
			Print 'The course is not being offered in that semester by the same department to which student belong to.'
			end

			if @v_found > 0
			begin
			rollback
			end

			insert into Registration 
			values 
			(@semester,	@r_no,	@c_id,
			(select Top(1) Courses_Semester.Section from Courses_Semester 
			where Courses_Semester.CourseID = @c_id and Courses_Semester.AvailableSeats > 0),
			(select Registration.GPA from Registration where CourseID = @prereq_clr and RollNumber = @r_no ))

			update Courses_Semester
			set Courses_Semester.AvailableSeats -= 1
			where Courses_Semester.Section = (select Top(1) Courses_Semester.Section from Courses_Semester 
			where Courses_Semester.CourseID = @c_id and Courses_Semester.AvailableSeats > 0)

			insert into ChallanForm 
			values (@semester,	@r_no,	( 7000 * (select Courses.CreditHours from Courses where CourseID = @c_id)),'Paid')

			declare @fc varchar(20) = ( select Courses.CourseName from Courses where CourseID = @c_id),
			@fs varchar(2) = ( select Top(1) Courses_Semester.Section from Courses_Semester where Courses_Semester.CourseID = @c_id and Courses_Semester.AvailableSeats > 0)

			Print 'Registation to '+@fc+' Section '+@fs+' Successful.'
end

exec Register
@r_no = 1,
@c_id = 10,
@semester = 'Spring2017'
go