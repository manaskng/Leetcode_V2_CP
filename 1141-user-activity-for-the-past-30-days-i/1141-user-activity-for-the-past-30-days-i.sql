select activity_date as day,
count(distinct user_id) as active_users
from Activity 
group by day
having datediff(cast("2019-07-27" as date),activity_date) <30
and datediff(cast("2019-07-27" as date),activity_date) >=0;