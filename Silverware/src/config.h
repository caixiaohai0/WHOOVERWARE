#include "defines.h"
#include "hardware.h"

// PLEASE SELECT THE PIDS THAT MATCH YOUR BUILD DETAILS IN THE PID.C FILE!!!!!!!!!  THEN ADJUST TORQUE BOOST
// AS INSTRUCTED IN THE PID SET.  TORQUE BOOST IS HERE IN CONFIG.H IN THE MOTOR OUTPUT SETTINGS SECTION.

//**********************************************************************************************************************
//***********************************************HARDWARE SELECTION*****************************************************

// *************DEFINE FLIGHT CONTROLLER HARDWARE
// *************SELECT ONLY ONE 
// *************uncomment BWHOOP define for bwhoop, bwhoop pro, E011C Santa Edition, and Beta FPV Lite Flight Controllers
// *************uncomment E011 define for E011 flight Controller
// *************uncomment H8mini_blue_board for the H8 mini flight controller with blue circuit board
//#define BWHOOP
//#define E011
#define H8mini_blue_board //7元四轴
//#define Alienwhoop_ZERO


//**********************************************************************************************************************
//***********************************************RECEIVER SETTINGS******************************************************

// *************rate in deg/sec
// *************for acro mode
#define MAX_RATE 860.0
#define MAX_RATEYAW 500.0

// *************max angle for level mode
#define MAX_ANGLE_HI 70.0f

// ************* low rates multiplier if rates are assigned to a channel
#define LOW_RATES_MULTI 0.5f

// *************EXPO from 0.00 to 1.00 , 0 = no exp
// *************positive = less sensitive near center 
#define EXPO_XY 0.8
#define EXPO_YAW 0.6

// *************transmitter stick adjustable deadband for roll/pitch/yaw
// *************.01f = 1% of stick range - comment out to disable
#define STICKS_DEADBAND .01f

// *************Radio protocol selection
// *************select only one
//#define RX_CG023_PROTOCOL
//#define RX_H7_PROTOCOL
//#define RX_BAYANG_PROTOCOL
#define RX_BAYANG_PROTOCOL_TELEMETRY
//#define RX_BAYANG_PROTOCOL_BLE_BEACON
//#define RX_BAYANG_BLE_APP
//#define RX_CX10BLUE_PROTOCOL
//#define RX_SBUS

// *************Transmitter Type Selection
//#define USE_STOCK_TX
//#define USE_DEVO
#define USE_MULTI

// *******************************SWITCH SELECTION*****************************
// *************CHAN_ON - on always ( all protocols)
// *************CHAN_OFF - off always ( all protocols)
// *************Aux channels are selectable as CHAN_5 through CHAN_10 for DEVO and MULTIMODULE users
// *************Toy transmitter mapping is CHAN_5 (rates button), CHAN_6 (stick gestures RRD/LLD), 
//**************CHAN_7 (headfree button), CHAN_8 (roll trim buttons), CHAN_9 (pitch trim buttons)

//*************Idle up-Arm switch
//*************comment out to disable
#define IDLE_UP CHAN_5
#define IDLE_THR 0.01f

//*************Assign feature to auxiliary channel.  NOTE - Switching on LEVELMODE is required for any leveling modes to 
//*************be active.  With LEVELMODE active - MCU will apply RACEMODE if racemode channel is on, HORIZON if horizon 
//*************channel is on, or racemodeHORIZON if both channels are on - and will be standard LEVELMODE if neither 
//*************racemode or horizon are switched on.
#define LEVELMODE CHAN_ON
#define RATES CHAN_ON
#define LEDS_ON CHAN_ON

// *************switch for fpv / other, requires fet
// *************comment out to disable
//#define FPV_ON CHAN_ON

// *************start in level mode for toy tx.
//#define AUX1_START_ON

// *************automatically remove center bias in toy tx ( needs throttle off for 1 second )
//#define STOCK_TX_AUTOCENTER



//**********************************************************************************************************************
//***********************************************VOLTAGE SETTINGS*******************************************************

// *************battery saver
// *************do not start software if battery is too low
// *************flashes 2 times repeatedly at startup
//#define STOP_LOWBATTERY

// *************voltage to start warning
#define VBATTLOW 3.5

// *************compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// *************calculate above factor automatically
#define AUTO_VDROP_FACTOR

// *************voltage hysteresys in volts
#define HYST 0.10

// *************lower throttle when battery below treshold - forced landing low voltage cutoff
//#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0




//**********************************************************************************************************************
//***********************************************FILTER SETTINGS********************************************************

// *************gyro low pass filter ( iir )
// *************set only one below - kalman, 1st order, or second order - and adjust frequency
//**************ABOVE 100 ADJUST IN INCRIMENTS OF 20, BELOW 100 ADJUST IN INCRIMENTS OF 10
#define SOFT_KALMAN_GYRO KAL1_HZ_90
//#define SOFT_LPF_1ST_HZ 80
//#define SOFT_LPF_2ND_HZ 80


// *************D term low pass filter type - set only one below and adjust frequency if adjustable filter is used
// *************1st order adjustable, second order adjustable, or 3rd order fixed (non adjustable)
//#define DTERM_LPF_1ST_HZ 100
#define  DTERM_LPF_2ND_HZ 100
//#define DTERM_LPF3_88

//**********************************************************************************************************************
//***********************************************MOTOR OUTPUT SETTINGS**************************************************

// *************enable motor output filter - select and adjust frequency
#define MOTOR_FILTER2_ALPHA MFILT1_HZ_90
//#define MOTOR_KAL KAL1_HZ_70

// *************pwm frequency for motor control
// *************a higher frequency makes the motors more linear
// *************in Hz
#define PWMFREQ 32000

// *************motor curve to use - select one
// *************the pwm frequency has to be set independently
#define MOTOR_CURVE_NONE
//#define MOTOR_CURVE_6MM_490HZ
//#define MOTOR_CURVE_85MM_8KHZ
#define MOTOR_CURVE_85MM_32KHZ
//#define BOLDCLASH_716MM_8K
//#define BOLDCLASH_716MM_24K

// *************clip feedforward attempts to resolve issues that occur near full throttle
//#define CLIP_FF

// *************torque boost is a highly eperimental feature.  it is a lpf D term on motor outputs that will accelerate the response
// *************of the motors when the command to the motors is changing by increasing or decreasing the voltage thats sent.  It differs
// *************from throttle transient compensation in that it acts on all motor commands - not just throttle changes.  this feature
// *************is very noise sensative so D term specifically has to be lowered and gyro/d filtering may need to be increased.
// *************reccomendation right now is to leave boost at or below 2, drop your p gains a few points, then cut your D in half and 
// *************retune it back up to where it feels good.  I'm finding about 60 to 65% of my previous D value seems to work.
#define TORQUE_BOOST 8.0

// *************makes throttle feel more poppy - can intensify small throttle imbalances visible in FPV if factor is set too high
#define THROTTLE_TRANSIENT_COMPENSATION 
#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 4.0 
 
// *************throttle angle compensation in level mode
//#define AUTO_THROTTLE

// *************mix lower throttle reduces thrust imbalances by reducing throttle proportionally to the adjustable reduction percent
// *************mix increase throttle increases the authority of the pid controller at lowest throttle values like airmode when combined with idle up
// *************mix3 has a stronger effect and works better with brushless
//#define MIX_LOWER_THROTTLE
#define MIX_THROTTLE_REDUCTION_PERCENT 10
//#define MIX_INCREASE_THROTTLE

//#define MIX_LOWER_THROTTLE_3
//#define MIX_INCREASE_THROTTLE_3

// *************invert yaw pid for "PROPS OUT" configuration
//#define INVERT_YAW_PID



//**********************************************************************************************************************
//***********************************************ADDITIONAL FEATURES****************************************************

// *************lost quad beeps using motors (30 sec timeout)
//#define MOTOR_BEEPS

// *************0 - 7 - power for telemetry
#define TX_POWER 7

// *************Flash saving features
//#define DISABLE_GESTURES2

// *************led brightness in-flight ( solid lights only)
// *************0- 15 range
#define LED_BRIGHTNESS 15

// *************external buzzer - pins in hardware.h
//#define BUZZER_ENABLE

// *************Comment out to disable pid tuning gestures
#define PID_GESTURE_TUNING
#define COMBINE_PITCH_ROLL_PID_TUNING

// *************flash save method
// *************flash_save 1: pids + accel calibration
// *************flash_save 2: accel calibration to option bytes
#define FLASH_SAVE1
//#define FLASH_SAVE2


// enable inverted flight code ( brushless only )
//#define INVERTED_ENABLE
//#define FN_INVERTED CH_OFF //for brushless only







//#############################################################################################################################
//#############################################################################################################################
// debug / other things
// this should not be usually changed
//#############################################################################################################################
//#############################################################################################################################

// Gyro LPF filter frequency
// gyro filter 0 = 250hz delay 0.97mS
// gyro filter 1 = 184hz delay 2.9mS
// gyro filter 2 = 92hz delay 3.9mS
// gyro filter 3 = 41hz delay 5.9mS (Default)
// gyro filter 4 = 20hz
// gyro filter 5 = 10hz
// gyro filter 6 = 5hz
// gyro filter 7 = 3600hz delay 0.17mS
#define GYRO_LOW_PASS_FILTER 0

// disable inbuilt expo functions
//#define DISABLE_EXPO

#define DISABLE_FLIP_SEQUENCER
#define STARTFLIP CHAN_OFF

// level mode "manual" trims ( in degrees)
// pitch positive forward
// roll positive right
#define TRIM_PITCH 0.0
#define TRIM_ROLL 0.0

// disable motors for testing
//#define NOMOTORS

// throttle direct to motors for thrust measure
// #define MOTORS_TO_THROTTLE

// throttle direct to motors for thrust measure as a flight mode
//#define MOTORS_TO_THROTTLE_MODE MULTI_CHAN_8


// loop time in uS
// this affects soft gyro lpf frequency if used
#define LOOPTIME 1000

// failsafe time in uS
#define FAILSAFETIME 1000000  // one second

// max rate used by level pid ( limit )
#define LEVEL_MAX_RATE 360

// debug things ( debug struct and other)
//#define DEBUG

// rxdebug structure
//#define RXDEBUG

// enable motors if pitch / roll controls off center (at zero throttle)
// possible values: 0 / 1
// use in acro build only
#define ENABLESTIX 0
#define ENABLESTIX_TRESHOLD 0.3
#define ENABLESTIX_TIMEOUT 1e6

// overclock to 64Mhz
//#define ENABLE_OVERCLOCK


// limit minimum motor output to a value (0.0 - 1.0)
//#define MOTOR_MIN_ENABLE
#define MOTOR_MIN_VALUE 0.05





#pragma diag_warning 1035 , 177 , 4017
#pragma diag_error 260

//--fpmode=fast





// define logic - do not change
///////////////

// used for pwm calculations
#ifdef ENABLE_OVERCLOCK
#define SYS_CLOCK_FREQ_HZ 64000000
#else
#define SYS_CLOCK_FREQ_HZ 48000000
#endif



#ifdef MOTOR_BEEPS
#ifdef USE_ESC_DRIVER
#warning "MOTOR BEEPS_WORKS WITH BRUSHED MOTORS ONLY"
#endif
#endif



// for the ble beacon to work after in-flight reset
#ifdef RX_BAYANG_PROTOCOL_BLE_BEACON
#undef STOP_LOWBATTERY
#endif


// gcc warnings in main.c



//Hardware defines moved from hardware.h so that board selection of bwhoop or e011 can be performed in config.h file

#ifdef BWHOOP
//LEDS
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED2PIN GPIO_Pin_3
#define LED2PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_90_CW

// SPI PINS DEFINITONS & RADIO
#if defined(RX_SBUS) || defined(RX_DSMX_2048) || defined(RX_DSM2_1024)
#define SERIAL_RX_SPEKBIND_BINDTOOL_PIN GPIO_Pin_3
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOF
#define RADIO_XN297L
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.001364
#define ADC_REF 1.17857f

// MOTOR PINS
#define MOTOR0_PIN_PB1 // motor 0 back-left
#define MOTOR1_PIN_PA4 // motor 1 front-left
#define MOTOR2_PIN_PA6 // motor 2 back-right
#define MOTOR3_PIN_PA7 // motor 3 front-right
#endif

#ifdef E011
//LEDS
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED2PIN GPIO_Pin_3
#define LED2PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_90_CW
#define SOFTI2C_PUSHPULL_CLK

// SPI PINS DEFINITONS & RADIO
#if defined(RX_SBUS) || defined(RX_DSMX_2048) || defined(RX_DSM2_1024)
#define SERIAL_RX_SPEKBIND_BINDTOOL_PIN GPIO_Pin_3
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOF
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOA
#define RADIO_XN297L
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.001364
#define ADC_REF 1.17857f

// Assingment of pin to motor
#define MOTOR0_PIN_PA6 // motor 0 back-left
#define MOTOR1_PIN_PA4 // motor 1 front-left
#define MOTOR2_PIN_PB1 // motor 2 back-right
#define MOTOR3_PIN_PA7 // motor 3 front-right
#endif

#ifdef H8mini_blue_board
//LEDS
#define LED_NUMBER 4
#define LED1PIN GPIO_Pin_5
#define LED1PORT GPIOB
#define LED2PIN GPIO_Pin_12
#define LED2PORT GPIOA
#define LED3PIN GPIO_Pin_15
#define LED3PORT GPIOA
#define LED4PIN GPIO_Pin_2
#define LED4PORT GPIOB

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_7
#define SOFTI2C_SDAPORT GPIOB
#define SOFTI2C_SCLPIN GPIO_Pin_6
#define SOFTI2C_SCLPORT GPIOB
#define SOFTI2C_GYRO_ADDRESS 0x68
#define SOFTI2C_PUSHPULL_CLK
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x78 // common h8 gyro
#define GYRO_ID_3 0x7D
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_180

// SPI PINS DEFINITONS & RADIO
#if defined(RX_SBUS) || defined(RX_DSMX_2048) || defined(RX_DSM2_1024)
#define SERIAL_RX_SPEKBIND_BINDTOOL_PIN GPIO_Pin_3
#define SERIAL_RX_PIN GPIO_Pin_14
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource14
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_4WIRE
#define SPI_MOSI_PIN GPIO_Pin_7
#define SPI_MOSI_PORT GPIOA
#define SPI_MISO_PIN GPIO_Pin_6
#define SPI_MISO_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_5
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_4
#define SPI_SS_PORT GPIOA
#define RADIO_XN297
#define RADIO_CHECK
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_0
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_7
#define ADC_SCALEFACTOR 0.15
#define ADC_REF 1.17857f

// Assingment of pin to motor
#define MOTOR0_PIN_PB8 // motor 0 back-left
#define MOTOR1_PIN_PA11 // motor 1 front-left
#define MOTOR2_PIN_PA3 // motor 2 back-right
#define MOTOR3_PIN_PA8 // motor 3 front-right
#endif

#ifdef Alienwhoop_ZERO
//LEDS
#define LED_NUMBER 1
#define LED1PIN GPIO_Pin_0
#define LED1PORT GPIOF
#define LED2PIN GPIO_Pin_0
#define LED2PORT GPIOA

//SOFT I2C & GYRO
#define SOFTI2C_SDAPIN GPIO_Pin_10
#define SOFTI2C_SDAPORT GPIOA
#define SOFTI2C_SCLPIN GPIO_Pin_9
#define SOFTI2C_SCLPORT GPIOA
#define SOFTI2C_GYRO_ADDRESS 0x68
//#define SOFTI2C_GYRO_ADDRESS 0x69
#define GYRO_ID_1 0x68
#define GYRO_ID_2 0x98 // new id
#define GYRO_ID_3 0x78
#define GYRO_ID_4 0x72 
#define SENSOR_ROTATE_90_CCW

// SPI PINS DEFINITONS & RADIO
#if defined(RX_SBUS) || defined(RX_DSMX_2048) || defined(RX_DSM2_1024)
#define SERIAL_RX_SPEKBIND_BINDTOOL_PIN GPIO_Pin_2
#define SERIAL_RX_SPEKBIND_RX_PIN GPIO_Pin_3
#define SERIAL_RX_PIN GPIO_Pin_3
#define SERIAL_RX_PORT GPIOA
#define SERIAL_RX_SOURCE GPIO_PinSource3
#define SERIAL_RX_CHANNEL GPIO_AF_1
#define SOFTSPI_NONE
//dummy spi placeholders
#define SPI_MOSI_PIN GPIO_Pin_x
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_y
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_z
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#else
#define SOFTSPI_3WIRE
#define SPI_MOSI_PIN GPIO_Pin_3
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_2
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_1
#define SPI_SS_PORT GPIOA
#define RADIO_CHECK
#define RADIO_XN297L
#endif

//VOLTAGE DIVIDER
#define BATTERYPIN GPIO_Pin_5
#define BATTERYPORT GPIOA
#define BATTERY_ADC_CHANNEL ADC_Channel_5
#define ADC_SCALEFACTOR 0.002423
#define ADC_REF 1.0f


// MOTOR PINS
// MOTOR PINS
#define MOTOR0_PIN_PA7
//#define MOTOR1_PIN_PA4  //2nd Draft prototype patch
//#define MOTOR2_PIN_PB1  //2nd Draft prototype patch
#define MOTOR1_PIN_PB1
#define MOTOR2_PIN_PA4
#define MOTOR3_PIN_PA6
#endif


