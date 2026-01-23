1SELECT
2  s.user_id,
3  ROUND(
4    COALESCE(
5      SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) * 1.0
6      / NULLIF(COUNT(c.user_id), 0),
7      0
8    ),
9    2
10  ) AS confirmation_rate
11FROM Signups s
12LEFT JOIN Confirmations c
13  ON s.user_id = c.user_id
14GROUP BY s.user_id;
15