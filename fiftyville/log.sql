-- Read the description of the crime scene on the date of the crime.
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = "Humphrey Street";

-- Finding the number plates and names belonging in a 10 minute window.
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.activity = 'exit'
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
ORDER BY bakery_security_logs.minute;

-- Finding the transcript of the witnesses.
SELECT name, transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;

 -- Eugene gives a clue that the thief went to a atm to withdraw money so checking the atm records.
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- Finding the names that go with the account numbers.
SELECT name, atm_transactions.amount
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';

-- Bruce has now come by in 2 different sets of data. Adding to supsects.

-- Raymond also gave a hint pointing toward =s the earliest flight leaving from a airport in fiftyville.
SELECT abbreviation, full_name, city
FROM airports
WHERE city = 'Fiftyville';

-- We find out there is only one airport in fiftyville so lets check the records.
SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id =
(SELECT id FROM airports WHERE city = 'Fiftyville')
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour, flights.minute;

-- It appears the first flight is towards New York City. Let's check the records of the people who flew there.
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
ORDER BY passengers.passport_number;

-- Bruce agian ; ) pretty sure he is the thief now.

-- Going through phone records to find the accomplice.
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;

-- Finding the receiver of bruce's call
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration = 45
ORDER BY phone_calls.duration;

-- Robin is the accomplice.

-- So.... Bruce is the thief helped by Robin and went to New York City
-- Fun problem set btw : )