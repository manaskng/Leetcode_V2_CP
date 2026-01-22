1# Write your MySQL query statement below
2SELECT
3    name,
4    population,
5    area
6FROM World 
7WHERE 
8    area >= 3000000 OR
9    population >= 25000000 ;