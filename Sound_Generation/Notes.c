/**
 * @file Notes.c
 *
 * @brief Source file for the notes.
 *
 * This file contains the notes definitions for frequency
 *
 * @author Daniel Garcia
 */
 
#include "Notes.h"

// Using float for space
const float C2  = 65.41f;
const float Cs2 = 69.30f;
const float D2  = 73.42f;
const float Eb2 = 77.78f;
const float E2  = 82.41f;
const float F2  = 87.31f;
const float Fs2 = 92.50f;
const float G2  = 98.00f;
const float Gs2 = 103.8f;
const float A2  = 110.0f;
const float Bb2 = 116.5f;
const float B2  = 123.5f;

const float C3  = 130.8f;
const float Cs3 = 138.6f;
const float D3  = 146.8f;
const float Eb3 = 155.6f;
const float E3  = 164.8f;
const float F3  = 174.6f;
const float Fs3 = 185.0f;
const float G3  = 196.0f;
const float Gs3 = 207.7f;
const float A3  = 220.0f;
const float Bb3 = 233.1f;
const float B3  = 246.9f;

const float C4  = 261.6f;
const float Cs4 = 277.2f;
const float D4  = 293.7f;
const float Eb4 = 311.1f;
const float E4  = 329.6f;
const float F4  = 349.2f;
const float Fs4 = 370.0f;
const float G4  = 392.0f;
const float Gs4 = 415.3f;
const float A4  = 440.0f;
const float Bb4 = 466.2f;
const float B4  = 493.9f;

const float C5  = 523.3f;
const float Cs5 = 554.4f;
const float D5  = 587.3f;
const float Eb5 = 622.3f;
const float E5  = 659.3f;
const float F5  = 698.5f;
const float Fs5 = 740.0f;
const float G5  = 784.0f;
const float Gs5 = 830.6f;
const float A5  = 880.0f;
const float Bb5 = 932.3f;
const float B5  = 987.8f;

const float C6  = 1047.0f;
const float Cs6 = 1109.0f;
const float D6  = 1175.0f;
const float Eb6 = 1245.0f;
const float E6  = 1319.0f;
const float F6  = 1397.0f;
const float Fs6 = 1480.0f;
const float G6  = 1568.0f;
const float Gs6 = 1661.0f;
const float A6  = 1760.0f;
const float Bb6 = 1865.0f;
const float B6  = 1976.0f;

const float C7  = 2093.0f;
const float Cs7 = 2217.5f;
const float D7  = 2349.3f;
const float Eb7 = 2489.0f;
const float E7  = 2637.0f;
const float F7  = 2793.8f;
const float Fs7 = 2960.0f;
const float G7  = 3136.0f;
const float Gs7 = 3322.4f;
const float A7  = 3520.0f;
const float Bb7 = 3729.3f;
const float B7  = 3951.1f;


// Tetris Theme
const float tetris_notes[] = {
    E5, B4, C5, D5, C5, B4,
    A4, A4, C5, E5, D5, C5,
    B4, C5, D5, E5,
    C5, A4, A4, A4, B4, C5,

    D5, F5, A5, G5, F5,
    E5, C5, E5, D5, C5,
    B4, B4, C5, D5, E5,
    C5, A4, A4, REST,

    E5, B4, C5, D5, C5, B4,
    A4, A4, C5, E5, D5, C5,
    B4, C5, D5, E5,
    C5, A4, A4, A4, B4, C5,

    D5, F5, A5, G5, F5,
    E5, C5, E5, D5, C5,
    B4, B4, C5, D5, E5,
    C5, A4, A4, REST,

    E5, C5,
    D5, B4,
    C5, A4,
    Gs4, B4, REST,
    E5, C5,
    D5, B4,
    C5, E5, A5,
    Gs5
};

// 1 = whole note, 2 = half note, 4 = quarter notes, 8 = eighth notes.
const int tetris_dur[] = {
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 8, 4, 8, 8,

    4, 8, 4, 8, 8,
    4, 8, 4, 8, 8,
    4, 8, 8, 4, 4,
    4, 4, 4, 4,

    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 8, 4, 8, 8,

    4, 8, 4, 8, 8,
    4, 8, 4, 8, 8,
    4, 8, 8, 4, 4,
    4, 4, 4, 4,

    2, 2,
    2, 2,
    2, 2,
    2, 4, 8,
    2, 2,
    2, 2,
    4, 4, 2,
    2
};

const int length_tetris = sizeof(tetris_notes) / sizeof(tetris_notes[0]);

// Harry Potter Theme
const float harryp_notes[] = {
    REST, D4,
    G4, Bb4, A4,
    G4, D5,
    C5,
    A4,
    G4, Bb4, A4,
    F4, Gs4,
    D4,
    D4,

    G4, Bb4, A4,
    G4, D5,
    F5, E5,
    Eb5, B4,
    Eb5, D5, Cs5,
    Cs4, B4,
    G4,
    Bb4,

    D5, Bb4,
    D5, Bb4,
    Eb5, D5,
    Cs5, A4,
    Bb4, D5, Cs5,
    Cs4, D4,
    D5,
    REST, Bb4,

    D5, Bb4,
    D5, Bb4,
    F5, E5,
    Eb5, B4,
    Eb5, D5, Cs5,
    Cs4, Bb4,
    G4
};

const int harryp_dur[] = {
    2, 4,
    4, 8, 4,
    2, 4,
    2,
    2,
    4, 8, 4,
    2, 4,
    1,
    4,

    4, 8, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1,
    4,

    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1,
    4, 4,

    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1
};

const int length_harryp = sizeof(harryp_notes) / sizeof(harryp_notes[0]);
