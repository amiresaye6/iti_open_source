use sakila; -- by Amir Alsayed  :__:

-- 1. Select the title, description, and length of all films that are longer than 120  minutes. Sort them from the longest to the shortest 

select title, description, length 
from film
where length > 120
order by length desc;

-- 2. Find all films that have a rental_rate of 0.99 or 2.99, but their replacement_cost is greater than 20.00 

select *
from film
where replacement_cost > 20 and rental_rate in (0.99, 2.99);

-- 3. Count the total number of films available in each rating (G, PG, R, etc.) 

select rating, count(*) as count
from film
group by rating;

-- 4. List the customer_ids who have made more than 30 separate payments in the payment table. 

select customer_id
from payment
group by customer_id
having count(*) > 30;

-- 5. Get all "Cities" in the database and the "Country" they belong to, but only for cities located in 'Egypt'

select *, "Egypt" as country
from city
where country_id = (
	select country_id
    from country
    where country = "Egypt"
    );

-- 6. Display a list of all films and the names of the actors who starred in them. (show film id, title and actor name)

select f.film_id as "Film Id", f.title as "Film Title", concat(a.first_name, " ", a.last_name) as "Actor Name"
from film f
join film_actor fa
on f.film_id = fa.film_id
join actor a
on a.actor_id = fa.actor_id;


-- 7. Find all customers who have rented a movie but haven't returned it yet. (show the customer name and the film title). 

select concat(c.first_name, " ", c.last_name) as "Customer Name", f.title as "Film title"
from customer c
join (
	select *
	from rental
	where return_date is null
    ) r
on c.customer_id = r.customer_id
join inventory i
on i.inventory_id = r.inventory_id
join  film f
on f.film_id = i.film_id;

-- 8. List the titles of all films whose length is greater than the average length of all films in the database. 

select title
from film
where length > (
	select avg(length)
    from film
    );
    
-- 9. Write a query to find the first_name, last_name, and email of customers who have zero rental records 

select *
from customer
where customer_id not in (
	select customer_id
    from rental
    );

-- 10. Create a view named customer_spending_summary. This view should display each customer's name, their total number of rentals, and the total amount of money they have paid. 

DROP VIEW if exists `sakila`.`customer_spending_summary`;

create view customer_spending_summary as
select concat(c.first_name, " ", c.last_name) as "name", count(distinct r.rental_id) as "number_of_rentals", sum(p.amount) as "amount_spent"
from customer c
join rental r
on c.customer_id = r.customer_id
join payment p
on p.rental_id = r.rental_id
group by c.customer_id;

select * from customer_spending_summary;

-- 11. Use the previous view to find only customers who spent more than $100 

select *
from customer_spending_summary
where amount_spent > 100;

-- ======================================== Built-in Function =====================================

-- 1. Display actor names in the format: LAST_NAME, First_name (e.g., GUINESS, Penelope). 

select upper(last_name), concat(upper(left(first_name, 1)), lower(substr(first_name, 2)))
from actor;

-- 2. Display all customer emails in lowercase and replace the domain @sakilacustomer.org with @iti-students.edu.

select lower(replace(email, "@sakilacustomer.org", "@iti-students.edu")) as "lower case iti email"
from customer;

-- 3. Display the first 50 characters of each film's description followed by "..." and call the column short_summary. 

select concat(left(description, 50), "...") as short_summary
from film;

-- 4. Find all customers who registered in the month of February (any year).

select *
from customer
where date_format(create_date, "%M") = "February";

-- 5. Extract the Quarter (1, 2, 3, or 4) from the payment_date (payment table) to see which part of the year is most profitable. 

select quarter(payment_date) as "quarter number", sum(amount) as "total revenu"
from payment
group by quarter(payment_date);

-- 6. Use CASE to label rentals as 'Cheap' (under $2), 'Mid' ($2-$4.99), or 'Expensive' (above $5).

select rental_id, amount,   case 
when amount < 2 then "Cheap"
when amount between 2 and  4.99 then "Mid"
else  "Expensive"
end as "Classification"
from payment;

-- =================Bonus:====================

-- 1. We want to reward our most loyal actors. Find the names of the actors who have appeared in 'Action' films more than 10 times. 

with action_actors_count as (
	select a.first_name, a.last_name,   count(*) as count_action
    from actor a
    join film_actor fa
    on a.actor_id = fa.actor_id
    join film f
    on f.film_id = fa.film_id
    join film_category fc
    on fc.film_id = f.film_id
    join category c
    on c.category_id = fc.category_id
    where c.name = "Action"
    group by a.actor_id, a.first_name, a.last_name

)
select first_name, last_name, count_action from action_actors_count
where count_action > 10;


-- Find the "Versatile Actors." These are actors who have appeared in more than 5 'Action' movies AND more than 5 'Drama' movies.

with action_actors_count as (
	select a.actor_id, a.first_name, a.last_name,   count(*) as count_action
    from actor a
    join film_actor fa
    on a.actor_id = fa.actor_id
    join film f
    on f.film_id = fa.film_id
    join film_category fc
    on fc.film_id = f.film_id
    join category c
    on c.category_id = fc.category_id
    where c.name = "Action"
    group by a.actor_id, a.first_name, a.last_name
    having count_action > 5

), drama_actors_count as (
	select a.actor_id, a.first_name, a.last_name,   count(*) as count_drama
    from actor a
    join film_actor fa
    on a.actor_id = fa.actor_id
    join film f
    on f.film_id = fa.film_id
    join film_category fc
    on fc.film_id = f.film_id
    join category c
    on c.category_id = fc.category_id
    where c.name = "Drama"
    group by a.actor_id, a.first_name, a.last_name
    having count_drama > 5

)
select a.first_name, a.last_name, a.count_action, d.count_drama
from action_actors_count a
join drama_actors_count d
on a.actor_id = d.actor_id;