/**
 * @file Notes.h
 *
 * @brief Header file for the note definitions and song and duration arrays.
 *
 * This file contains the notes definitions for frequency along with the note and duration arrays
 *
 * @NOTE Tetris, Harry Potter, and Pirates notes and duration array is credited to hibit-dev on GitHub
 * Link to their Repository: https://github.com/hibit-dev/buzzer/tree/master/src
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia
 */

#ifndef NOTES_H
#define NOTES_H
#define REST 0.0f // 
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

// Pirates Theme
extern const float pirates_notes[];
extern const int pirates_dur[];
extern const int length_pirates;

// Mario Theme
extern const float mario_notes[];
extern const int mario_dur[];
extern const int length_mario;

/**
 * @brief Plays the <song> melody.
 *
 * Iterates through the parallel arrays `<song>_notes[]` and `<song>_dur[]` up to
 * `length_<song>`. For each index `i`:
 *   - If PMOD BTN1 and BTN3 are both pressed simultaneously, abort playback:
 *       • Turn the buzzer off  
 *       • `break` out of the loop  
 *   - Read the note frequency from `<song>_notes[i]`. A REST value (0.0f) produces silence.
 *   - Compute the note duration in ms as:
 *       ```
 *       duration_ms = WHOLE_NOTE_DURATION / <song>_dur[i];
 *       ```
 *     where the integers in `<song>_dur[]` mean:  
 *       • `1` = whole note  
 *       • `2` = half note  
 *       • `4` = quarter note  
 *       • `8` = eighth note  
 *   - Call `Play_Note(<song>_notes[i], duration_ms)` to generate the tone.
 *   - After each note, insert a brief extra delay (e.g. `SysTick_Delay1ms(duration_ms * <factor>)`)
 *     to prevent notes from running together.
 *
 * @NOTE Tetris, Harry Potter, and Pirates notes and duration array is credited to hibit-dev on GitHub
 * Link to their Repository: https://github.com/hibit-dev/buzzer/tree/master/src
 *
 * @param  None
 *
 * @author Daniel Garcia Aguilar, Robert Rabenkogo Eboulia
 */

void Play_Tetris(void);
void Play_HarryPotter(void);
void Play_Pirates(void);
void Play_mario(void);

#endif // NOTES_H

