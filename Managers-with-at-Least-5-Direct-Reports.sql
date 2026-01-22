1# Write your MySQL query statement below
2#group according to the managerid with count then returnt he name of managers with that name
3SELECT e.name AS name FROM
4Employee e  JOIN ( 
5SELECT  managerId, COUNT(*)  AS EMPCNT
6FROM Employee
7GROUP BY managerId HAVING COUNT(*)>=5 ) t 
8WHERE e.id=t.managerId