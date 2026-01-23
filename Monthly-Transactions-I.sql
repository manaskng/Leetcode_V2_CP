1SELECT 
2    LEFT(trans_date, 7) AS month,
3    country, 
4    COUNT(id) AS trans_count,
5    SUM(state = 'approved') AS approved_count,
6    SUM(amount) AS trans_total_amount,
7    SUM((state = 'approved') * amount) AS approved_total_amount
8FROM 
9    Transactions
10GROUP BY 
11    month, country;