# Write your MySQL query statement below
#group according to the managerid with count then returnt he name of managers with that name
SELECT e.name AS name FROM
Employee e  JOIN ( 
SELECT  managerId, COUNT(*)  AS EMPCNT
FROM Employee
GROUP BY managerId HAVING COUNT(*)>=5 ) t 
WHERE e.id=t.managerId