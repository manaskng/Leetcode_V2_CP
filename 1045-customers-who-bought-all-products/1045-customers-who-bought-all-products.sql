SELECT DISTINCT C.customer_id
FROM Customer C
JOIN (
    SELECT customer_id, COUNT(DISTINCT product_key) AS cnt
    FROM Customer
    GROUP BY customer_id
) D 
ON C.customer_id = D.customer_id
WHERE D.cnt = (
    SELECT COUNT(*) 
    FROM Product
);
