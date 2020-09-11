import random
import csv

n_values = 20

with open('temperature-humidity.csv', 'w') as csvfile:
    fieldnames = ['Temperature', 'Humidity']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for _ in range(n_values):
        writer.writerow({'Temperature' : random.randint(0, 50), 'Humidity' : random.randint(1, 100)})