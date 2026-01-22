1# find earliest year of each product sold then return that table
2SELECT s.product_id, s.year AS first_year,s.quantity,s.price
3FROM Sales s JOIN(
4SELECT product_id , MIN(year)  as first_year FROM
5Sales GROUP BY product_id
6) t
7ON 
8s.product_id=t.product_id AND s.year=t.first_year
9