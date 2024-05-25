# Finite State Transducer (FST)
This project implements a Finite State Transducer (FST) in C++. An FST is a type of finite state machine where each transition between states is associated with an input symbol and an output symbol. The FST reads a string of input symbols and generates a string of output symbols as it transitions through states.

## Features
+ Reads the FST configuration from an input file.
+ Processes an input string to generate corresponding output strings based on the FST transitions.
+ Supports multiple transitions and final states.

## Files
+ FST.h - Header file defining the FST class.
+ FST.cpp - Implementation of the FST class methods.
+ main.cpp - Main program that sets up the FST, reads the configuration, and processes an input string.
+ date.in - Input file containing the FST configuration.
+ FST Configuration File (date.in)

## The configuration file follows this format:

+ Number of input alphabet symbols.
+ List of input alphabet symbols.
+ Number of output alphabet symbols.
+ List of output alphabet symbols.
+ Number of states.
+ List of states.
+ Initial state.
+ Number of final states.
+ List of final states.
+ Number of transitions.
+ List of transitions in the format: **current_state input_symbol next_state output_symbol**.
