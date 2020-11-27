# aditiaa2-aayyah2-jchint2-cgurna2
Final Project

**Description:**
Our final project for CS 225 utilizes an airports dataset (https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat) to calculate the most efficient path based on different user preferences. 

1) Most efficient path (with geographic distance travelled as the metric for efficiency)
2) Landmark path (selecting most efficient path that passes through the given landmarks)

We take in the user's input (starting airport, ending airport, and any landmarks) formatted with quotes. 
Ex: To enter ORD, type "ORD" when prompted. Yes, the quotes are required!

The complete path is printed out when the calculations are complete. This is formatted with a pipe (|) as the delimiter between different airport codes. 
Ex: ORD|DXB|MAA

**To Build:**
This project is written in C++.
In order to "make", open the main directory on your terminal and run:
1) make
2) ./final

You will then be prompted to enter your inputs and landmarks. 

If you're curious about our testing process and want to see our test cases in action, run:
1) make test
2) ./test

**Usage:**
We think this is a cool representation of what can be done with graph data structures and traversals. Though this is historical data (and therefore not up to date), it's useful to illustrate the complexities of air travel and how CS can be used to quickly and efficiently calculate paths. 

**Authors:**
Aditi Adya (aditiaa2)
Aparna Ayyah (aayyah2)
Chaahat Gurnani (cgurna2)
Joshmita Chintala (jchint2)

**We hope you enjoy our project!**
