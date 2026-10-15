from itertools import combinations

words = ["apple","banana","kiwi","mango"]

#1.List Comprehenesions : words with length > 4
list_result = [word for word in words if len(word) > 4]
print("List Comprehensions:", list_result)

#2. Dictionary Comprehensions : word and its length
dict_result = {word:len(word) for word in words}
print("Dict Comprehensions:", dict_result)

# 3. Set comprehension: unique words
set_result = {word for word in words}
print("Set Comprehensions:", set_result)

def all_combinations(items):
    result = []
    for r in range(len(items) + 1):
        result.extend(combinations(items,r))
    return result
items = {"A","B","C"}
print("All Combinations:", all_combinations(sorted(items)))


# Assignement 2
import time

# 1. Generator function for Fibonacci numbers
def fibonacci(n):
    a,b = 0,1
    for i in range(n):
        yield a
        a,b = b, a+b
print("Fibonacci Series")
for num in fibonacci(10):
    print(num,end=" ")
print("\n")

# 2. Decorator to measure execution time
def timer(func):
    def wrapper():
        start = time.time()
        func()
        end = time.time()
        print("Execution Time:", end - start, "seconds")
    return wrapper

@timer
def display():
    for i in range(100000):
        pass
    print("Function executed")

display()

# 3. Context manager to open and close a file
with open("sample.txt","w") as file:
    file.write("Hello Python")
print("\nFile written and closed successfully.")

with open("sample.txt","r") as file:
    print("File Content: ",file.read())


# Assignement 3
#Annotate a function that calculates the average of a list 
#of numbers with type hints.

def cal_average(numbers: list[float]) -> float:
    return sum(numbers) / len(numbers)
numbers = [10,20,30,40,50]
print("Average:", cal_average(numbers))

# Part 2: Advanced string formatting

name = "Bhargav"
marks = 89.567
subject = "Python"

# Using f-strings
print(f"Name: {name}")
print(f"Subject: {subject}")
print(f"Marks: {marks:.1f}")

# Using format() method
print("Name: {}".format(name))
print("Subject: {}".format(subject))
print("Marks: {:.2f}".format(marks))

#Assignement 4 

from abc import ABC, abstractmethod

# Part 1: Abstract Base Class
class Animal(ABC):
    @abstractmethod
    def sound(self):
        pass
#Two Parent Classes
class Walker:
    def walk(self):
        print("Animal Walks")

class Swimmer:
    def swim(self):
        print("Animal Swims")

#Multiple Inheritance
class Dog(Animal,Walker,Swimmer):
    def sound(self):
        print("Dog barks")

dog = Dog()
dog.sound()
dog.walk()
dog.swim()

# Part 2: Metaclass that adds a logging attribute
class LogMeta(type):
    def __new__(cls, name, bases, attrs):
        attrs["logging"] = "Logging enabled"
        return super().__new__(cls, name, bases, attrs)

class Student(metaclass=LogMeta):
    pass

class Teacher(metaclass=LogMeta):
    pass

print(Student.logging)
print(Teacher.logging)


#Assignement 5

# Custom Vector class
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Overload + operator
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    # Overload - operator
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    # Overload * operator (scalar multiplication)
    def __mul__(self, number):
        return Vector(self.x * number, self.y * number)

    # String representation for users
    def __str__(self):
        return f"({self.x}, {self.y})"

    # Official representation
    def __repr__(self):
        return f"Vector({self.x}, {self.y})"

    # Return number of components
    def __len__(self):
        return 2


v1 = Vector(2, 3)
v2 = Vector(4, 5)

print("Vector 1:", str(v1))
print("Vector 2:", repr(v2))
print("Addition:", v1 + v2)
print("Subtraction:", v1 - v2)
print("Multiplication:", v1 * 2)
print("Length:", len(v1))


#Assignment 6

import pickle
import json

# Complex object
student = {
    "name": "Bhargav",
    "age": 20,
    "marks": [85, 90, 95],
    "address": {"city": "Pune", "state": "Maharashtra"}
}

# Part 1: Save and load using Pickle
with open("student.pkl", "wb") as file:
    pickle.dump(student, file)

with open("student.pkl", "rb") as file:
    data1 = pickle.load(file)

print("Pickle Data:", data1)

# Part 2: Save and load using JSON
with open("student.json", "w") as file:
    json.dump(student, file)

with open("student.json", "r") as file:
    data2 = json.load(file)

print("JSON Data:", data2)

#Assignment 7

from collections import deque, namedtuple

# Part 1: Circular Buffer using deque
buffer = deque(maxlen=3)

buffer.append(10)
buffer.append(20)
buffer.append(30)

print("Buffer:", list(buffer))

buffer.append(40)  # Oldest element is removed automatically

print("After adding 40:", list(buffer))


# Part 2: 3D Point using namedtuple
Point = namedtuple("Point", ["x", "y", "z"])

p = Point(10, 20, 30)

print("3D Point:", p)
print("X coordinate:", p.x)
print("Y coordinate:", p.y)
print("Z coordinate:", p.z)

#Assignment 8

import numpy as np
import pandas as pd
import heapq

# Part 1: NumPy array operations and broadcasting
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

print("Array A:", a)
print("Array B:", b)
print("Addition:", a + b)
print("Multiplication:", a * b)

# Broadcasting
print("Broadcasting:", a + 10)


# Part 2: Pandas CSV, cleaning and analysis
data = {
    "Name": ["Amit", "Riya", "John", "Neha"],
    "Marks": [80, 90, np.nan, 70],
    "Age": [20, 21, 19, 20]
}

# Create a sample CSV file
pd.DataFrame(data).to_csv("students.csv", index=False)

# Load CSV into DataFrame
df = pd.read_csv("students.csv")
print("\nOriginal Data:")
print(df)

# Data cleaning: fill missing marks with average
df["Marks"] = df["Marks"].fillna(df["Marks"].mean())

print("\nCleaned Data:")
print(df)

print("\nAverage Marks:", df["Marks"].mean())
print("Highest Marks:", df["Marks"].max())


# Part 3: Priority queue using heapq
pq = []

heapq.heappush(pq, (2, "Write assignment"))
heapq.heappush(pq, (1, "Study Python"))
heapq.heappush(pq, (3, "Play game"))

print("\nPriority Queue:")
while pq:
    priority, task = heapq.heappop(pq)
    print(priority, task)


#Assignment 9

import logging
import threading

# Part 1: Logging system
logging.basicConfig(
    filename="app.log",
    level=logging.DEBUG,
    format="%(levelname)s: %(message)s",
    force=True
)

logging.debug("This is a debug message")
logging.info("Program started")
logging.warning("This is a warning")
logging.error("An error occurred")
logging.critical("Critical error occurred")

print("Logging messages saved to app.log")


# Part 2: Custom exception and exception chaining
class MyError(Exception):
    pass

def divide(a, b):
    try:
        return a / b
    except ZeroDivisionError as e:
        raise MyError("Cannot divide by zero") from e

try:
    divide(10, 0)
except MyError as e:
    print("Custom Exception:", e)
    print("Original Exception:", e.__cause__)


# Part 3: Thread-safe file access
lock = threading.Lock()

def write_file(message):
    with lock:
        with open("shared.txt", "a") as file:
            file.write(message + "\n")

t1 = threading.Thread(target=write_file, args=("Hello from Thread 1",))
t2 = threading.Thread(target=write_file, args=("Hello from Thread 2",))

t1.start()
t2.start()

t1.join()
t2.join()

print("Thread-safe file writing completed")

with open("shared.txt", "r") as file:
    print(file.read())
