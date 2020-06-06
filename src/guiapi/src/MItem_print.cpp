#include "MItem_print.hpp"
#include "marlin_client.h"
#include "menu_vars.h"
#include "eeprom.h"
/*****************************************************************************/
//MI_NOZZLE
MI_NOZZLE::MI_NOZZLE()
    : WI_SPIN_U16_t(uint16_t(marlin_vars()->target_nozzle),
        MenuVars::nozzle_range.data(), label, 0, true, false) {}
void MI_NOZZLE::OnClick() {
    marlin_set_target_nozzle(value);
}

/*****************************************************************************/
//MI_HEATBED
MI_HEATBED::MI_HEATBED()
    : WI_SPIN_U08_t(uint8_t(marlin_vars()->target_bed),
        MenuVars::bed_range.data(), label, 0, true, false) {}
void MI_HEATBED::OnClick() {
    marlin_set_target_bed(value);
}

/*****************************************************************************/
//MI_PRINTFAN
MI_PRINTFAN::MI_PRINTFAN()
    : WI_SPIN_U08_t(uint8_t(marlin_vars()->fan_speed),
        MenuVars::printfan_range.data(), label, 0, true, false) {}
void MI_PRINTFAN::OnClick() {
    marlin_set_fan_speed(value);
}

/*****************************************************************************/
//MI_SPEED
MI_SPEED::MI_SPEED()
    : WI_SPIN_U16_t(uint16_t(marlin_vars()->print_speed),
        MenuVars::feedrate_range.data(), label, 0, true, false) {}
void MI_SPEED::OnClick() {
    marlin_set_print_speed(value);
}

/*****************************************************************************/
//MI_FLOWFACT
MI_FLOWFACT::MI_FLOWFACT()
    : WI_SPIN_U16_t(uint16_t(marlin_vars()->flow_factor),
        MenuVars::flowfact_range.data(), label, 0, true, false) {}
void MI_FLOWFACT::OnClick() {
    marlin_set_flow_factor(value);
}

/*****************************************************************************/
//MI_BABYSTEP
MI_BABYSTEP::MI_BABYSTEP()
    : WI_SPIN_t<float>(marlin_vars()->z_offset, MenuVars::zoffset_fl_range.data(), MenuVars::zoffset_prt_format, label, 0, true, false) {}
void MI_BABYSTEP::OnClick() {
    eeprom_set_var(EEVAR_ZOFFSET, marlin_get_var(MARLIN_VAR_Z_OFFSET));
}
bool MI_BABYSTEP::Change(int dif) {
    bool ret = WI_SPIN_t<float>::Change(dif);
    marlin_set_z_offset(value);
    return ret;
}