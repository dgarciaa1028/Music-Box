/**
 * @file Notes.h
 *
 * @brief Header file for the notes.
 *
 * This file contains the notes definitions for frequency along with the note and duration arrays
 *
 * @NOTE Tetris and Harry Potter notes and duration array is credited to hibit-dev on GitHub
 * Link to their Repository: https://github.com/hibit-dev/buzzer/tree/master/src
 *
 * @author Daniel Garcia
 */

#ifndef NOTES_H
#define NOTES_H
#define REST 0.0f
#define WHOLE_NOTE_DURATION 1600
#include <stdint.h>

// Notes from C2 to B6 (extern declarations as floats)

extern const float C2, Cs2, D2, Eb2, E2, F2, Fs2, G2, Gs2, A2, Bb2, B2;
extern const float C3, Cs3, D3, Eb3, E3, F3, Fs3, G3, Gs3, A3, Bb3, B3;
extern const float C4, Cs4, D4, Eb4, E4, F4, Fs4, G4, Gs4, A4, Bb4, B4;
extern const float C5, Cs5, D5, Eb5, E5, F5, Fs5, G5, Gs5, A5, Bb5, B5;
extern const float C6, Cs6, D6, Eb6, E6, F6, Fs6, G6, Gs6, A6, Bb6, B6;

// Tetris Theme
extern const float tetris_notes[];
extern const int tetris_dur[];
extern const int length_tetris;

// Harry Potter Theme
extern const float harryp_notes[];
extern const int harryp_dur[];
extern const int length_harryp;

extern const float pirates_notes[];
extern const int pirates_dur[];
extern const int length_pirates;

void Play_Tetris(void);
void Play_HarryPotter(void);
void Play_Pirates(void);

#endif // NOTES_H

