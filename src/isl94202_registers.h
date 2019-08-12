/* LibreSolar Battery Management System firmware
 * Copyright (c) 2016-2019 Martin Jäger (www.libre.solar)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>

// register map (16 bit words)

// Overvoltage Threshold
// Charge Detect Pulse Width
#define ISL94202_OVL_CPW    (0x00U)
#define ISL94202_OVL_Pos    (0x0U)
#define ISL94202_OVL_Msk    (0xFFFU << ISL94202_OVL_Pos)
#define ISL94202_CPW_Pos    (0xC)
#define ISL94202_CPW_Msk    (0xFU << ISL94202_CPW_Pos)

// Overvoltage Recovery
#define ISL94202_OVR        (0x02U)
#define ISL94202_OVR_Pos    (0x0U)
#define ISL94202_OVR_Msk    (0xFFFU << ISL94202_OVR_Pos)

// Undervoltage Threshold
// Load Detect Pulse Width
#define ISL94202_UVL_LPW    (0x04U)
#define ISL94202_UVL_Pos    (0x0U)
#define ISL94202_UVL_Msk    (0xFFFU << ISL94202_UVL_Pos)
#define ISL94202_LPW_Pos    (0xC)
#define ISL94202_LPW_Msk    (0xFU << ISL94202_LPW_Pos)

// Undervoltage Recovery
#define ISL94202_UVR        (0x06U)
#define ISL94202_UVR_Pos    (0x0U)
#define ISL94202_UVR_Msk    (0xFFFU << ISL94202_UVR_Pos)

// Overvoltage Lockout Threshold
#define ISL94202_OVLO       (0x08U)
#define ISL94202_OVLO_Pos   (0x0U)
#define ISL94202_OVLO_Msk   (0xFFFU << ISL94202_OVLO_Pos)

// Undervoltage Lockout Threshold
#define ISL94202_UVLO       (0x0AU)
#define ISL94202_UVLO_Pos   (0x0U)
#define ISL94202_UVLO_Msk   (0xFFFU << ISL94202_UVLO_Pos)

// End-of-Charge (EOC) Threshold
#define ISL94202_EOC        (0x0CU)
#define ISL94202_EOC_Pos    (0x0U)
#define ISL94202_EOC_Msk    (0xFFFU << ISL94202_EOC_Pos)

// Low Voltage Charge Level
#define ISL94202_LVCH       (0x0EU)
#define ISL94202_LVCH_Pos   (0x0U)
#define ISL94202_LVCH_Msk   (0xFFFU << ISL94202_LVCH_Pos)

// Overvoltage Delay Time Out
#define ISL94202_OVDT       (0x10U)
#define ISL94202_OVDT_Pos   (0x0U)
#define ISL94202_OVDT_Msk   (0xFFFU << ISL94202_OVDT_Pos)

// Undervoltage Delay Time Out
#define ISL94202_UVDT       (0x12U)
#define ISL94202_UVDT_Pos   (0x0U)
#define ISL94202_UVDT_Msk   (0xFFFU << ISL94202_UVDT_Pos)

// Open-Wire Timing (OWT)
#define ISL94202_OWT        (0x14U)
#define ISL94202_OWT_Pos    (0x0U)
#define ISL94202_OWT_Msk    (0x3FFU << ISL94202_OWT_Pos)

// Discharge Overcurrent Time Out/Threshold
#define ISL94202_OCDT_OCD   (0x16U)
#define ISL94202_OCDT_Pos   (0x0U)
#define ISL94202_OCDT_Msk   (0xFFFU << ISL94202_OCDT_Pos)
#define ISL94202_OCD_Pos    (0xCU)
#define ISL94202_OCD_Msk    (0x7U << ISL94202_OCD_Pos)

// Charge Overcurrent Time Out/Threshold
#define ISL94202_OCCT_OCC   (0x18U)
#define ISL94202_OCCT_Pos   (0x0U)
#define ISL94202_OCCT_Msk   (0xFFFU << ISL94202_OCCT_Pos)
#define ISL94202_OCC_Pos    (0xCU)
#define ISL94202_OCC_Msk    (0x7U << ISL94202_OCC_Pos)

// Discharge Short-Circuit Time Out/Threshold
#define ISL94202_SCDT_SCD   (0x1AU)
#define ISL94202_SCDT_Pos   (0x0U)
#define ISL94202_SCDT_Msk   (0xFFFU << ISL94202_SCDT_Pos)
#define ISL94202_SCD_Pos    (0xCU)
#define ISL94202_SCD_Msk    (0x7U << ISL94202_SCD_Pos)

// Cell Balance Minimum Voltage (CBMIN)
#define ISL94202_CBVL       (0x1CU)
#define ISL94202_CBVL_Pos   (0x0U)
#define ISL94202_CBVL_Msk   (0xFFFU << ISL94202_CBVL_Pos)

// Cell Balance Maximum Voltage (CBMAX)
#define ISL94202_CBVU       (0x1EU)
#define ISL94202_CBVU_Pos   (0x0U)
#define ISL94202_CBVU_Msk   (0xFFFU << ISL94202_CBVU_Pos)

// Cell Balance Minimum Differential Voltage (CBMINDV)
#define ISL94202_CBDL       (0x20U)
#define ISL94202_CBDL_Pos   (0x0U)
#define ISL94202_CBDL_Msk   (0xFFFU << ISL94202_CBDL_Pos)

// Cell Balance Maximum Differential Voltage (CBMAXDV)
#define ISL94202_CBDU       (0x22U)
#define ISL94202_CBDU_Pos   (0x0U)
#define ISL94202_CBDU_Msk   (0xFFFU << ISL94202_CBDU_Pos)

// Cell Balance On Time (CBON)
#define ISL94202_CBONT      (0x24U)
#define ISL94202_CBONT_Pos  (0x0U)
#define ISL94202_CBONT_Msk  (0xFFFU << ISL94202_CBON_Pos)

// Cell Balance Off Time (CBOFF)
#define ISL94202_CBOFT      (0x26U)
#define ISL94202_CBOFT_Pos  (0x0U)
#define ISL94202_CBOFT_Msk  (0xFFFU << ISL94202_CBOF_Pos)

// Cell Balance Minimum Temperature Limit (CBUTS)
#define ISL94202_CBUTS      (0x28U)
#define ISL94202_CBUTS_Pos  (0x0U)
#define ISL94202_CBUTS_Msk  (0xFFFU << ISL94202_CBUTS_Pos)

// Cell Balance Minimum Temperature Recovery Level (CBUTR)
#define ISL94202_CBUTR      (0x2AU)
#define ISL94202_CBUTR_Pos  (0x0U)
#define ISL94202_CBUTR_Msk  (0xFFFU << ISL94202_CBUTR_Pos)

// Cell Balance Maximum Temperature Limit (CBOTS)
#define ISL94202_CBOTS      (0x2CU)
#define ISL94202_CBOTS_Pos  (0x0U)
#define ISL94202_CBOTS_Msk  (0xFFFU << ISL94202_CBOTS_Pos)

// Cell Balance Maximum Temperature Recovery Level (CBOTR)
#define ISL94202_CBOTR      (0x2EU)
#define ISL94202_CBOTR_Pos  (0x0U)
#define ISL94202_CBOTR_Msk  (0xFFFU << ISL94202_CBOTR_Pos)

// Charge Over-Temperature Voltage
#define ISL94202_COTS       (0x30U)
#define ISL94202_COTS_Pos   (0x0U)
#define ISL94202_COTS_Msk   (0xFFFU << ISL94202_COTS_Pos)

// Charge Over-Temperature Recovery Voltage
#define ISL94202_COTR       (0x32U)
#define ISL94202_COTR_Pos   (0x0U)
#define ISL94202_COTR_Msk   (0xFFFU << ISL94202_COTR_Pos)

// Charge Under-Temperature Voltage
#define ISL94202_CUTS       (0x34U)
#define ISL94202_CUTS_Pos   (0x0U)
#define ISL94202_CUTS_Msk   (0xFFFU << ISL94202_CUTS_Pos)

// Charge Under-Temperature Recovery Voltage
#define ISL94202_CUTR       (0x36U)
#define ISL94202_CUTR_Pos   (0x0U)
#define ISL94202_CUTR_Msk   (0xFFFU << ISL94202_CUTR_Pos)

// Discharge Over-Temperature Voltage
#define ISL94202_DOTS       (0x38U)
#define ISL94202_DOTS_Pos   (0x0U)
#define ISL94202_DOTS_Msk   (0xFFFU << ISL94202_DOTS_Pos)

// Discharge Over-Temperature Recovery Voltage
#define ISL94202_DOTR       (0x3AU)
#define ISL94202_DOTR_Pos   (0x0U)
#define ISL94202_DOTR_Msk   (0xFFFU << ISL94202_DOTR_Pos)

// Discharge Under-Temperature Voltage
#define ISL94202_DUTS       (0x3CU)
#define ISL94202_DUTS_Pos   (0x0U)
#define ISL94202_DUTS_Msk   (0xFFFU << ISL94202_DUTS_Pos)

// Discharge Under-Temperature Recovery Voltage
#define ISL94202_DUTR       (0x3EU)
#define ISL94202_DUTR_Pos   (0x0U)
#define ISL94202_DUTR_Msk   (0xFFFU << ISL94202_DUTR_Pos)

// Internal Over-Temperature Voltage
#define ISL94202_IOTS       (0x40U)
#define ISL94202_IOTS_Pos   (0x0U)
#define ISL94202_IOTS_Msk   (0xFFFU << ISL94202_IOTS_Pos)

// Internal Over-Temperature Recovery Voltage
#define ISL94202_IOTR       (0x42U)
#define ISL94202_IOTR_Pos   (0x0U)
#define ISL94202_IOTR_Msk   (0xFFFU << ISL94202_IOTR_Pos)

// Sleep Level Voltage
#define ISL94202_SLL        (0x44U)
#define ISL94202_SLL_Pos    (0x0U)
#define ISL94202_SLL_Msk    (0xFFFU << ISL94202_SLL_Pos)

// Sleep Delay
// Watchdog Timer (WDT)
#define ISL94202_SLT_WDT    (0x46U)
#define ISL94202_SLT_Pos    (0x0U)
#define ISL94202_SLT_Msk    (0x7FFU << ISL94202_SLT_Pos)
#define ISL94202_WDT_Pos    (0xBU)
#define ISL94202_WDT_Msk    (0x1FU << ISL94202_WDT_Pos)

// Mode Timer
// Cell Configuration
#define ISL94202_MOD_CELL   (0x48U)
#define ISL94202_MOD_Pos    (0x0U)
#define ISL94202_MOD_Msk    (0xFFU << ISL94202_MOD_Pos)
#define ISL94202_CELL_Pos   (0x8U)
#define ISL94202_CELL_Msk   (0xFFU << ISL94202_CELL_Pos)

// Feature Controls
#define ISL94202_FC         (0x4AU)
// Cell fail PSD
#define ISL94202_CFPSD_Pos  (0x0U)
#define ISL94202_CFPSD_Msk  (0xFFFU << ISL94202_CFPSD_Pos)
// xTemp2 Mode Control
#define ISL94202_XT2M_Pos   (0x0U)
#define ISL94202_XT2M_Msk   (0xFFFU << ISL94202_XT2M_Pos)
// External Temp Gain
#define ISL94202_TGAIN_Pos  (0x0U)
#define ISL94202_TGAIN_Msk  (0xFFFU << ISL94202_TGAIN_Pos)
// Precharge FET Enable
#define ISL94202_PCFETE_Pos (0x0U)
#define ISL94202_PCFETE_Msk (0xFFFU << ISL94202_PCFETE_Pos)
// Disable Open-Wire-Scan
#define ISL94202_DOWD_Pos   (0x0U)
#define ISL94202_DOWD_Msk   (0xFFFU << ISL94202_DOWD_Pos)
// Open-Wire PSD
#define ISL94202_OWPSD_Pos  (0x0U)
#define ISL94202_OWPSD_Msk  (0xFFFU << ISL94202_OWPSD_Pos)
// CB during Discharge
#define ISL94202_CBDD_Pos   (0x0U)
#define ISL94202_CBDD_Msk   (0xFFFU << ISL94202_CBDD_Pos)
// CB during Charge
#define ISL94202_CBDC_Pos   (0x0U)
#define ISL94202_CBDC_Msk   (0xFFFU << ISL94202_CBDC_Pos)
// DFET on during UV (Charging)
#define ISL94202_DFODUV_Pos (0x0U)
#define ISL94202_DFODUV_Msk (0xFFFU << ISL94202_DFODUV_Pos)
// CFET on during OV (Discharging)
#define ISL94202_DFODOV_Pos (0x0U)
#define ISL94202_DFODOV_Msk (0xFFFU << ISL94202_DFODOV_Pos)
// Enable UVLO Power-Down
#define ISL94202_UVLOPD_Pos (0x0U)
#define ISL94202_UVLOPD_Msk (0xFFFU << ISL94202_UVLOPD_Pos)
// Enable CBAL during EOC
#define ISL94202_CBEOC_Pos  (0x0U)
#define ISL94202_CBEOC_Msk  (0xFFFU << ISL94202_CBEOC_Pos)

// RAM registers

#define ISL94202_CELLMIN    (0x8AU)
#define ISL94202_CELLMAX    (0x8CU)
#define ISL94202_ISNS       (0x8EU)
#define ISL94202_CELL1      (0x90U)
#define ISL94202_CELL2      (0x92U)
#define ISL94202_CELL3      (0x94U)
#define ISL94202_CELL4      (0x96U)
#define ISL94202_CELL5      (0x98U)
#define ISL94202_CELL6      (0x9AU)
#define ISL94202_CELL7      (0x9CU)
#define ISL94202_CELL8      (0x9EU)
#define ISL94202_IT         (0xA0U)
#define ISL94202_XT1        (0xA2U)
#define ISL94202_XT2        (0xA4U)
#define ISL94202_VBATT      (0xA6U)
#define ISL94202_VRGO       (0xA8U)
#define ISL94202_ADC        (0xAAU)
/*
#define ISL94202__Pos       (0x0U)
#define ISL94202__Msk       (0xFFFU << )

#define ISL94202_           (0xU)
#define ISL94202__Pos       (0x0U)
#define ISL94202__Msk       (0xFFFU << )
*/

static const int OCD_thresholds [8] =
    { 4, 8, 16, 24, 32, 48, 64, 96 }; // mV

static const int OCC_thresholds [8] =
    { 1, 2, 4, 6, 8, 12, 16, 24 }; // mV

static const int DSC_thresholds [8] =
    { 16, 24, 32, 48, 64, 96, 128, 256 }; // mV

// Scale Value for delay times (first 2 bytes)
#define ISL94202_DELAY_US   (0U)
#define ISL94202_DELAY_MS   (1U)
#define ISL94202_DELAY_S    (2U)
#define ISL94202_DELAY_MIN  (3U)