drop database IF  EXISTS ITIProjectdb;
create database IF NOT EXISTS ITIProjectdb;
use ITIProjectdb;

SET @OLD_FK_CHECKS = @@FOREIGN_KEY_CHECKS;
SET FOREIGN_KEY_CHECKS = 0;

CREATE TABLE Professors
(
  pId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  detptId INT,
  FOREIGN KEY (detptId) REFERENCES Departments(detptId)
);

CREATE TABLE Departments
(
  detptId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  headId INT,
  FOREIGN KEY (headId) REFERENCES Professors(pId)
);

CREATE TABLE QuestionsBank
(
  qId INT PRIMARY KEY,
  questionText VARCHAR(255) NOT NULL,
  grade FLOAT NOT NULL,
  pId INT NOT NULL,
  FOREIGN KEY (pId) REFERENCES Professors(pId)
);

CREATE TABLE choises
(
  choiceId INT PRIMARY KEY AUTO_INCREMENT,
  choise VARCHAR(255) NOT NULL,
  isCorrect BOOLEAN NOT NULL DEFAULT 0 ,
  qId INT NOT NULL,
  FOREIGN KEY (qId) REFERENCES QuestionsBank(qId)
);

CREATE TABLE Courses
(
  courseId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  detptId INT NOT NULL,
  FOREIGN KEY (detptId) REFERENCES Departments(detptId)
);

CREATE TABLE Exams
(
  examId INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  startTime DATETIME NOT NULL,
  endTime DATETIME NOT NULL,
  totalGrade INT NOT NULL,
  pId INT NOT NULL,
  courseId INT NOT NULL,
  FOREIGN KEY (pId) REFERENCES Professors(pId),
  FOREIGN KEY (courseId) REFERENCES Courses(courseId)
);

CREATE TABLE ExamQuestions
(
  qId INT NOT NULL,
  examId INT NOT NULL,
  PRIMARY KEY (qId, examId),
  FOREIGN KEY (qId) REFERENCES QuestionsBank(qId),
  FOREIGN KEY (examId) REFERENCES Exams(examId)
);

CREATE TABLE Teaches
(
  degree VARCHAR(50) NOT NULL,
  level INT NOT NULL,
  pId INT NOT NULL,
  courseId INT NOT NULL,
  PRIMARY KEY (degree, level, pId, courseId),
  FOREIGN KEY (pId) REFERENCES Professors(pId),
  FOREIGN KEY (courseId) REFERENCES Courses(courseId)
);

CREATE TABLE Students
(
  sId INT PRIMARY KEY,
  userName VARCHAR(50) UNIQUE NOT NULL,
  name VARCHAR(50) NOT NULL,
  password VARCHAR(50) NOT NULL,
  faculty VARCHAR(50) NOT NULL,
  degree VARCHAR(50) NOT NULL,
  level INT NOT NULL
);

CREATE TABLE evaluateCourse
(
  rating INT NOT NULL CHECK (rating BETWEEN 1 AND 5),
  comment VARCHAR(255) NOT NULL,
  sId INT NOT NULL,
  courseId INT NOT NULL,
  PRIMARY KEY (sId, courseId),
  FOREIGN KEY (sId) REFERENCES Students(sId),
  FOREIGN KEY (courseId) REFERENCES Courses(courseId)
);


CREATE TABLE StudentCourses (
  sId INT NOT NULL,
  courseId INT NOT NULL,
  PRIMARY KEY (sId, courseId),
  FOREIGN KEY (sId) REFERENCES Students(sId),
  FOREIGN KEY (courseId) REFERENCES Courses(courseId)
);



CREATE TABLE evaluateProfessor
(
  rating INT NOT NULL CHECK (rating BETWEEN 1 AND 5),
  comment VARCHAR(255) NOT NULL,
  pId INT NOT NULL,
  sId INT NOT NULL,
  courseId INT NOT NULL,
  PRIMARY KEY (pId, sId, courseId),
  FOREIGN KEY (pId) REFERENCES Professors(pId),
  FOREIGN KEY (sId) REFERENCES Students(sId),
  FOREIGN KEY (courseId) REFERENCES Courses(courseId)
);

CREATE TABLE attemp
(
  attemptId INT NOT NULL PRIMARY KEY ,
  score INT NOT NULL ,
  sId INT NOT NULL,
  examId INT NOT NULL,
  UNIQUE (sId, examId),
  FOREIGN KEY (sId) REFERENCES Students(sId),
  FOREIGN KEY (examId) REFERENCES Exams(examId)
);


CREATE TABLE answers
(
  choiceId INT NOT NULL ,
  attemptId INT NOT NULL ,
  PRIMARY KEY (attemptId , choiceId),
  FOREIGN KEY (choiceId) REFERENCES choices(choiceId),
  FOREIGN KEY (attemptId) REFERENCES attemp(attemptId)
);