#pragma once

#include "marlin_events.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef enum {
    DLG_serial_printing,
    DLG_load_unload,
    DLG_count
} dialog_t;

typedef enum {
    DLG_type_change,
    DLG_type_load,
    DLG_type_unload
} load_unload_type_t;

typedef enum {
    btns_none,
    btns_stop,
    btns_continue,
    btns_disable,
    btns_yes_no,
    btns_count
} multibtns_t;
extern const uint8_t multibtn_numbers[btns_count];

typedef enum {
    load_seq_parking,
    load_seq_wait_temp,
    load_seq_push_filament,
    load_seq_make_sure_filament_loaded,
    load_seq_inserting,
    load_seq_loading,
    load_seq_purging,
    load_seq_color_correct,
    load_seq_count
} load_sequence_t;

extern const multibtns_t load_sequence_multibtns[load_seq_count];

//open dialog has paramener
//because I need to set caption of change filament dialog (load / unload / change)
//use extra state of statemachine to set caption woud be cleaner, but I can miss events
//only last sent event is guaranteed  to pass its data
typedef void (*dialog_open_cb_t)(dialog_t, uint8_t);                                                 //open dialog
typedef void (*dialog_close_cb_t)(dialog_t);                                                         //close dialog
typedef void (*dialog_change_cb_t)(dialog_t, uint8_t phase, uint8_t progress_tot, uint8_t progress); //change dialog state or progress

#ifdef __cplusplus
}
#endif //__cplusplus