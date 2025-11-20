-- Queries 
--  -------------------------------1---------------------------------- 
-- Write a query that enables the students to view their results per course
use itiprojectdb;
SELECT
    s.sId,
    s.name AS studentName,
    c.courseId,
    c.name AS courseName,
    SUM(e.totalGrade) AS ExamsTotalGrade, -- مجموع درجات الامتحانات في الكورس
    SUM(a.score) AS studentTotalScore      -- مجموع درجات الطالب في الكورس
FROM Students s
JOIN attemp a
    ON s.sId = a.sId
JOIN Exams e
    ON a.examId = e.examId
JOIN Courses c
    ON e.courseId = c.courseId
GROUP BY
    s.sId,
    c.courseId;
    
    
  -- another solution show the degrees for 
  -- every student in every exam and the course that include that exam  
    SELECT
    s.sId,
    s.name AS studentName,
    c.courseId,
    c.name AS courseName,
    e.examId,
    e.name AS examName,
    e.totalGrade AS examTotalGrade,
    a.score AS studentScore
FROM Students s
JOIN attemp a
    ON s.sId = a.sId
JOIN Exams e
    ON a.examId = e.examId
JOIN Courses c
    ON e.courseId = c.courseId
ORDER BY
    s.sId,
    c.courseId,
    e.examId;




    
    -- --------------------------- 2 ------------------------------ 
    -- Write a query that enables the head of department to see evaluation of
-- each course and professor.
SELECT 
    d.name AS departmentName,
    h.name AS headName,
    c.name AS courseName,
    AVG(ec.rating) AS avgCourseRating,
    COUNT(ec.rating) AS totalCourseEvaluations,
    p.name AS professorName,
    AVG(ep.rating) AS avgProfessorRating,
    COUNT(ep.rating) AS totalProfessorEvaluations
FROM Departments d
JOIN Professors h ON h.pId = d.headId
JOIN Courses c ON c.detptId = d.detptId
 JOIN evaluateCourse ec ON ec.courseId = c.courseId
JOIN Professors p ON p.detptId = d.detptId
 JOIN evaluateProfessor ep 
       ON ep.pId = p.pId AND ep.courseId = c.courseId
GROUP BY 
    d.detptId, c.courseId, p.pId;
    
    
    
    
    
    
    -- ------------------------ 3 -----------------------------------
    -- Write a query that enables you to get top 10 high scores per course
SELECT
    s.sId,
    s.name AS studentName,
    c.courseId,
    c.name AS courseName,
     SUM(e.totalGrade) AS ExamsTotalGrade, 
    SUM(a.score) AS studentTotalScore
FROM Students s
JOIN attemp a
    ON s.sId = a.sId
JOIN Exams e
    ON a.examId = e.examId
JOIN Courses c
    ON e.courseId = c.courseId
WHERE c.courseId in(select distinct courseId from courses)
GROUP BY s.sId, c.courseId
ORDER BY c.courseId 
LIMIT 10;






-- ---------------------  4 ---------------------------------
-- Write a query to get the highest evaluation professor from the set of
-- professors teaching the same course
  SELECT 
    ep.courseId,
    c.name AS courseName,
    ep.pId AS professorId,
    p.name AS professorName,
    AVG(ep.rating) AS avgRating
FROM evaluateProfessor ep
JOIN Professors p ON ep.pId = p.pId
JOIN Courses c ON ep.courseId = c.courseId
GROUP BY ep.courseId, ep.pId
HAVING AVG(ep.rating) = (
    SELECT MAX(avgRating)
    FROM (
        SELECT AVG(rating) AS avgRating
        FROM evaluateProfessor
        WHERE courseId = ep.courseId
        GROUP BY pId
    ) AS x
);







    

