-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check reports from 28th July, 2021 on Humphrey Street
SELECT description FROM crime_scene_reports WHERE year = "2021" AND month = "7" AND day = "28" AND street = "Humphrey Street";

--Resuts: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. Littering took place at 16:36. No known witnesses.


-- Get the 3 Witnesses interview transcripts
SELECT transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript like "%bakery%";

-- Result: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.

-- Check names associated with phone number and passport number
SELECT name, phone_number, passport_number FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE day = 28 AND hour = 10 AND activity = "exit"


--|  name   |  phone_number  | passport_number |
---------+----------------+-----------------+
--| Vanessa | (725) 555-4692 | 2963008352      |
--| Bruce   | (367) 555-5533 | 5773159633      |
--| Barry   | (301) 555-4174 | 7526138472      |
--| Luca    | (389) 555-5198 | 8496433585      |
--| Sofia   | (130) 555-0289 | 1695452385      |
--| Iman    | (829) 555-5269 | 7049073643      |
--| Diana   | (770) 555-1861 | 3592750733      |
--| Kelsey  | (499) 555-9472 | 8294398571      |
--| Taylor  | (286) 555-6063 | 1988161715      |

SELECT DISTINCT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = 28
AND month = 7
AND year = 2021
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street'

--Results from above

--|  name   |

--| Luca    |
--| Kenny   |
--| Taylor  |
--| Bruce   |
--| Brooke  |
--| Iman    |
--| Benista |
--| Diana   |



--List airports
SELECT full_name, abbreviation, city, id
FROM airports
WHERE id IN (SELECT DISTINCT origin_airport_id FROM flights);

--|                full_name                | abbreviation |     city      | id |
--+-----------------------------------------+--------------+---------------+----+
--| O'Hare International Airport            | ORD          | Chicago       | 1  |
--| Beijing Capital International Airport   | PEK          | Beijing       | 2  |
--| Los Angeles International Airport       | LAX          | Los Angeles   | 3  |
--| LaGuardia Airport                       | LGA          | New York City | 4  |
--| Dallas/Fort Worth International Airport | DFS          | Dallas        | 5  |
--| Logan International Airport             | BOS          | Boston        | 6  |
--| Dubai International Airport             | DXB          | Dubai         | 7  |
--| Fiftyville Regional Airport             | CSF          | Fiftyville    | 8  |
+-----------------------------------------+--------------+---------------+----+

--Search flights from Fiftyville Regional Airport
SELECT *
FROM flights JOIN airports ON flights.origin_airport_id = airports.id
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = 8;


--| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | id | abbreviation |          full_name          |    city    |
--+----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-----------------------------+------------+
--| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
--| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
--| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
--| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
--| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
--+----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-----------------------------+------------+

-- Find the destination
SELECT airports.full_name, flights.id FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE month = 7 AND day = 29 AND flights.origin_airport_id = 8
ORDER BY hour LIMIT 1;

--|     full_name     | id |
--| LaGuardia Airport | 36 |
-- Destination of Bruce is New York City


-- Find the accomplice of Bruce.
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE caller = "(367) 555-5533" AND day = 28 AND duration < 60;

-- Accomplice is Robin