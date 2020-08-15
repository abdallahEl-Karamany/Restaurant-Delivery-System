# Restaurant Order Management & Delivery System

A C++ implementation of a restaurant order management and delivery system that handles order processing, motorcycle delivery assignments, and order cancellations in real-time.

## Overview

This system simulates a restaurant's delivery operations with the following key features:
- Order queue management
- Dynamic motorcycle delivery assignment
- Order cancellation handling
- Delivery time calculation
- Performance metrics tracking

## System Components

### Order Management
- Tracks order details including:
  - Order ID
  - Arrival time
  - Distance
  - Service time
  - Waiting time
  - Delivery cost

### Delivery Fleet
- Manages a fleet of motorcycles with:
  - Individual motorcycle IDs
  - Speed settings
  - Dynamic assignment to orders
  - Automatic return to available pool after delivery

### Performance Tracking
- Calculates and reports:
  - Average waiting time
  - Average service time
  - Total revenue
  - Number of completed orders
  - Number of cancelled orders

## Input Format

The system accepts input files in the following format:
```
[number_of_motorcycles]
[speed_of_motorcycles]
R [arrival_time] [order_id] [distance] [money]
X [cancel_time] [order_id]
```

Example:
```
9
6
R 2 3   21 300
R 2 300 33 400
X 15 1
```

## Output Format

The system generates detailed delivery reports including:
```
ID  Arrival_Time  Waiting_Time  Service_Time  Delivered_Time  Money
```

## Implementation Details

- Written in C++
- Uses data structures:
  - Linked lists for order and motorcycle management
  - Queues for cancellation handling
  - Custom classes for Orders and Motorcycles

## Performance Considerations

- The system processes orders in real-time with a 500ms simulation step
- Motorcycle assignments are optimized for minimal waiting time
- Order cancellations are handled efficiently through queue management
