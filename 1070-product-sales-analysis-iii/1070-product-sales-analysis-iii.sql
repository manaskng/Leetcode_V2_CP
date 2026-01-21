# find earliest year of each product sold then return that table
SELECT s.product_id, s.year AS first_year,s.quantity,s.price
FROM Sales s JOIN(
SELECT product_id , MIN(year)  as first_year FROM
Sales GROUP BY product_id
) t
ON 
s.product_id=t.product_id AND s.year=t.first_year
