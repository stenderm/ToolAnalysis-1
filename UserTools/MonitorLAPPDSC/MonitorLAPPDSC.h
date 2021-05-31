#ifndef MonitorLAPPDSC_H
#define MonitorLAPPDSC_H

#include <string>
#include <iostream>
#include <vector>

#include "Tool.h"
#include <Store.h>
#include <BoostStore.h>
#include <SlowControlMonitor.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "TMath.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TDatime.h"
#include "TPaveText.h"
#include "TFile.h"
#include "TPad.h"
#include "TAxis.h"
#include "TROOT.h"
#include "TH2F.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TObjectTable.h"
#include "TLatex.h"
#include "TText.h"
#include "TTree.h"
#include "TRandom3.h"

/**
 * \class MonitorLAPPDSC
 *
 * This is a blank template for a Tool used by the script to generate a new custom tool. Please fill out the description and author information.
*
* $Author: B.Richards $
* $Date: 2019/05/28 10:44:00 $
* Contact: b.richards@qmul.ac.uk
*/
class MonitorLAPPDSC: public Tool {


 public:

  MonitorLAPPDSC(); ///< Simple constructor
  bool Initialise(std::string configfile,DataModel &data); ///< Initialise Function for setting up Tool resources. @param configfile The path and name of the dynamic configuration file to read in. @param data A reference to the transient data class used to pass information between Tools.
  bool Execute(); ///< Execute function used to perform Tool purpose.
  bool Finalise(); ///< Finalise function used to clean up resources.

  //Configuration functions
  void ReadInConfiguration();
  void InitializeHists();

  //Read/Write functions
  void WriteToFile();
  void ReadFromFile(ULong64_t timestamp, double time_frame);

  //Draw functions
  void DrawLastFilePlots();
  void UpdateMonitorPlots(std::vector<double> timeFrames, std::vector<ULong64_t> endTimes, std::vector<std::string> fileLabels, std::vector<std::vector<std::string>> plotTypes);
  void DrawStatus_TempHumidity();
  void DrawStatus_LVHV();
  void DrawStatus_Trigger();
  void DrawStatus_Relay();
  void DrawStatus_Errors();
  void DrawStatus_Overview();
  void DrawTimeEvolutionLAPPDSC(ULong64_t timestamp_end, double time_frame, std::string file_ending);

  //Helper functions
  std::string convertTimeStamp_to_Date(ULong64_t timestamp);
  bool does_file_exist(std::string filename);

 private:

  //Configuration variables
  std::string outpath_temp;
  std::string outpath;
  std::string StartTime;
  double update_frequency;
  std::string path_monitoring;
  std::string img_extension;
  bool force_update;
  bool draw_marker;
  int verbosity;
  std::string plot_configuration;

  //Plot configuration variables
  std::vector<double> config_timeframes;
  std::vector<std::string> config_endtime;
  std::vector<std::string> config_label;
  std::vector<std::vector<std::string>> config_plottypes;
  std::vector<ULong64_t> config_endtime_long;

  //Time reference variables
  boost::posix_time::ptime *Epoch = nullptr;
  boost::posix_time::ptime current;
  boost::posix_time::time_duration period_update;
  boost::posix_time::time_duration duration;
  boost::posix_time::ptime last;
  boost::posix_time::ptime utc;
  boost::posix_time::time_duration current_stamp_duration;
  boost::posix_time::time_duration current_utc_duration;
  time_t t;
  std::stringstream title_time; 
  long current_stamp, current_utc;
  ULong64_t readfromfile_tend;
  double readfromfile_timeframe; 	//TODO: is this set in the code?
  ULong64_t t_current;

  //Variables to convert times
  double MSEC_to_SEC = 1000.;
  double SEC_to_MIN = 60.;
  double MIN_to_HOUR = 60.;
  double HOUR_to_DAY = 24.;
  ULong64_t utc_to_fermi = 2.7e12;  //6h clock delay in ADC clocks (timestamps in UTC time compared to Fermilab time)
  ULong64_t utc_to_t=21600000;  //6h clock delay in millisecons

  //Geometry variables
  Geometry *geom = nullptr;
  double tank_center_x, tank_center_y, tank_center_z;

  //Data
  SlowControlMonitor lappd_sc;

  //Plotting variables in vectors
  std::vector<ULong64_t> times_plot;
  std::vector<float> temp_plot;
  std::vector<float> humidity_plot;
  std::vector<int> hv_mon_plot;
  std::vector<float> hv_volt_plot;
  std::vector<bool> hv_stateset_plot;
  std::vector<int> lv_mon_plot;
  std::vector<bool> lv_stateset_plot;
  std::vector<float> lv_v33_plot;
  std::vector<float> lv_v25_plot;
  std::vector<float> lv_v12_plot;
  std::vector<float> hum_low_plot;
  std::vector<float> hum_high_plot;
  std::vector<float> temp_low_plot;
  std::vector<float> temp_high_plot;
  std::vector<int> flag_temp_plot;
  std::vector<int> flag_hum_plot;
  std::vector<bool> relCh1_plot;
  std::vector<bool> relCh2_plot;
  std::vector<bool> relCh3_plot;
  std::vector<bool> relCh1mon_plot;
  std::vector<bool> relCh2mon_plot;
  std::vector<bool> relCh3mon_plot;
  std::vector<float> trig1_plot;
  std::vector<float> trig0_plot;
  std::vector<float> trig1thr_plot;
  std::vector<float> trig0thr_plot;
  std::vector<float> trig_vref_plot;
  std::vector<float> light_plot;
  std::vector<int> num_errors_plot;
  std::vector<TDatime> labels_timeaxis;

  //canvas
  TCanvas *canvas_temp = nullptr;
  TCanvas *canvas_humidity = nullptr;
  TCanvas *canvas_light = nullptr;
  TCanvas *canvas_hv = nullptr;
  TCanvas *canvas_lv = nullptr;
  TCanvas *canvas_status_temphum = nullptr;
  TCanvas *canvas_status_lvhv = nullptr;
  TCanvas *canvas_status_relay = nullptr;
  TCanvas *canvas_status_trigger = nullptr;
  TCanvas *canvas_status_error = nullptr;  

  //graphs
  TGraph *graph_temp = nullptr;
  TGraph *graph_humidity = nullptr;
  TGraph *graph_light = nullptr;
  TGraph *graph_hv_volt = nullptr;
  TGraph *graph_lv_volt1 = nullptr;
  TGraph *graph_lv_volt2 = nullptr;
  TGraph *graph_lv_volt3 = nullptr;
  
  //multi-graphs
  TMultiGraph *multi_lv = nullptr;
  
  //legends
  TLegend *leg_lv = nullptr;

  //text
  TText *text_temphum_title = nullptr;
  TText *text_temp = nullptr;
  TText *text_hum = nullptr;
  TText *text_light = nullptr;
  TText *text_flag_temp = nullptr;
  TText *text_flag_hum = nullptr;

  //Verbosity variables
  int v_error = 0;
  int v_warning = 1;
  int v_message = 2;
  int v_debug = 3;
  int vv_debug = 4;

};


#endif