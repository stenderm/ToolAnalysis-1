#ifndef SRC_LAPPDConstants_H_
#define SRC_LAPPDConstants_H_


//Namespace for all the constants we need for the LAPPD simulation


namespace LAPPDConstants {

// All Delays are in ns, if not stated otherwise.

const int DelayEntries = 30;

//These values come from the .gbr file of the pickup board.
//The assumed speed is c/2
//IMPORTANT NOTE: The first two channels are calibration or synchronisation channels!
double leftSideLAPPDDelay[DelayEntries] = {0.239246, 0.206809, 0.360, 0.36041, 0.35792, 0.353124, 0.586332, 0.588687,
                                           0.587511, 0.586378, 0.578142, 0.586826, 1.54833, 1.54284, 1.54774, 1.54755,
                                           1.54528, 1.54273, 1.46617, 1.46464, 1.49473, 1.46782, 1.46823, 1.46553,
                                           1.23423, 1.23435, 1.23303, 1.23223, 1.23374, 1.2348 };

//IMPORTANT NOTE: The last two channels are calibration or synchronisation channels!
double rightSideLAPPDDelay[DelayEntries] = {1.23481, 1.23426, 1.23223, 1.23445, 1.23436, 1.23424, 1.46647, 1.46824,
                                            1.46783, 1.49474, 1.46514, 1.46653, 1.54566, 1.54608, 1.54693, 1.54774,
                                            1.54284, 1.54834, 0.586834, 0.578138, 0.585629, 0.587519, 0.586053, 0.585981,
                                            0.352459, 0.354052, 0.360418, 0.359968, 0.202251, 0.239128};

//IMPORTANT NOTE: The first two channels are calibration or synchronisation channels!
double channelToSumDelay[DelayEntries] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0, 0.0};




//--------------------------------------------------------------------------------------------------------------------------------
//synchronisation function parameters
//frequency of synchronisation signal in MHz
double wrFrequency = 250.0;

//voltage peak to peak for synchronisation signal in volt
double Vpp = 1.2;

//number of channels fed from one wr
int wrChannelNumber = 6;

//--------------------------------------------------------------------------------------------------------------------------------
//Comparator parameters
//In and out delay for the channel comparators
double comparatorDelay = 2.4;

//Threshold of the channel comparators in mV
double comparatorThreshold = 20.0;

//Signal length of the output of the channel comparators
double comparatorSigLength = 1.0;

//Amplitude of the output signal of the channel comparator in mV
double comparatorSigAmplitude = 200.0;

//In and out delay for the integral comparator
double sumComparatorDelay = 0.5;

//Threshold for the integral comparator in mV ToDo:Adjust this number!
double sumComparatorThreshold = 200.0;

//Integrator interval of the multiplicity comparator
double sumCompartorInterval = 100.0;

//--------------------------------------------------------------------------------------------------------------------------------

//Delay due to the signal from the anode traveling to the trigger board and then to the pickup board
double anodeToPickUpDelay = 0.0751;

//Delay due to the differential stripline from the sum comparator to the PSEC electronic
//Assumed that the signal speed is 4.5 ns/meter
double triggerToPSECDelay = 0.9;

}










































#endif
