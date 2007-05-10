#include "Validation/HcalRecHits/interface/HcalRecHitsValidation.h"

HcalRecHitsValidation::HcalRecHitsValidation(edm::ParameterSet const& conf) {
  // DQM ROOT output
  outputFile_ = conf.getUntrackedParameter<std::string>("outputFile", "myfile.root");

  if ( outputFile_.size() != 0 ) {
    edm::LogInfo("OutputInfo") << " Hcal RecHit Task histograms will be saved to '" << outputFile_.c_str() << "'";
  } else {
    edm::LogInfo("OutputInfo") << " Hcal RecHit Task histograms will NOT be saved";
  }
  
  dbe_ = 0;

  // get hold of back-end interface
  dbe_ = edm::Service<DaqMonitorBEInterface>().operator->();
   
  meTime = 0;
  Char_t histo[20];

  hcalselector_ = conf.getUntrackedParameter<std::string>("hcalselector", "all");

  if ( dbe_ ) {
    std::cout << " dbe_->setCurrentFolder" << std::endl; 
    dbe_->setCurrentFolder("HcalRecHitTask");
 
    if (hcalselector_ == "noise" ){

      sprintf  (histo, "e_hb" ) ;
      e_hb = dbe_->book1D(histo, histo,400, -2., 2. ) ;
      sprintf  (histo, "e_he" ) ;
      e_he = dbe_->book1D(histo, histo,400, -2., 2. ) ;
      sprintf  (histo, "e_ho" ) ;
      e_ho = dbe_->book1D(histo, histo,400, -2., 2. ) ;
      sprintf  (histo, "e_hfl" ) ;
      e_hfl = dbe_->book1D(histo, histo,1000, -5., 5. ) ;
      sprintf  (histo, "e_hfs" ) ;
      e_hfs = dbe_->book1D(histo, histo,1000, -5., 5. ) ;

    }
    // ************** BARREL   **********************************
    if (hcalselector_ == "HB" ){
      
      sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HB" ) ;
      meNumRecHitsCone    = dbe_->book1D(histo, histo, 80, 0 , 80.);

      sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HB");
      meNumRecHitsThresh = dbe_->book1D(histo, histo,   25, 0., 25.);          

      sprintf (histo, "HcalRecHitTask_number_of_rechits_HB" ) ;
      meNumRecHits    = dbe_->book1D(histo, histo, 80, 0 , 80.);

      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_0_HB" ) ;
      meEtaPhiDepth0= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_1_HB" ) ;
      meEtaPhiDepth1= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_2_HB" ) ;
      meEtaPhiDepth2= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_3_HB" ) ;
      meEtaPhiDepth3= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14); 

      sprintf (histo, "HcalRecHitTask_eta_of_rechits_HB" ) ;
      meEta = dbe_->book1D(histo, histo, 40, -1.74 , 1.74);
	 
      sprintf (histo, "HcalRecHitTask_phi_of_rechits_HB" ) ;
      mePhi = dbe_->book1D(histo, histo, 72, -3.14159, 3.14159);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HB" ) ;
      meEcalHcalEnergy= dbe_->book1D(histo,histo, 50 , 0., 200.);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HB" ) ;
      meEcalHcalEnergyCone =  dbe_->book1D(histo,histo, 50 , 0., 200.);  
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HB" ) ;
      me2D= dbe_->book2D(histo, histo, 1000, -5., 95.,  1100, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HB" ) ;
      me2Dprofile= dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 100.); 
            
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HB" ) ;
      meSumRecHitsEnergy= dbe_->book1D(histo,histo, 25 , -10., 160.);
      
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HB" ) ;
      meSumRecHitsEnergyCone= dbe_->book1D(histo,histo, 25 , -10., 160.);   

      sprintf (histo, "HcalRecHitTask_timing_HB" ) ;
      meTime = dbe_->book1D(histo, histo, 20000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HB" ) ;
      meRecHitsEnergy = dbe_->book1D(histo, histo, 2000 , -100. , 100.); 

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_2_HB" ) ;
      meRecHitsEnergyNoise = dbe_->book1D(histo, histo, 100 , -1. , 1.);       

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HB");
      meRecHitSimHit = dbe_->book2D(histo, histo, 1000, 0.,1.2,  1000, 0., 150.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HB");
      meRecHitSimHitProfile = dbe_->bookProfile(histo, histo, 100, 0.,1.1,  1000, 0., 150.);  

      sprintf (histo, "HcalRecHitTask_energy_hcal_vs_ecal_HB");
      meEnergyHcalVsEcal = dbe_->book2D(histo, histo, 1500, 0.,150.,  1500, 0., 150.);  

      sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HB");
      meNumEcalRecHitsCone = dbe_->book1D(histo, histo,   300, 0., 300.);    

    }

    // ********************** ENDCAP ************************************
    if (hcalselector_ == "HE" ){
      sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HE" ) ;
      meNumRecHitsCone    = dbe_->book1D(histo, histo, 40, 0 , 40.);

      sprintf (histo, "HcalRecHitTask_number_of_rechits_HE" ) ;
      meNumRecHits    = dbe_->book1D(histo, histo, 50, 0 , 230.);

      sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HE");
      meNumRecHitsThresh = dbe_->book1D(histo, histo,   30, 0., 30.);         


      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_0_HE" ) ;
      meEtaPhiDepth0= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_1_HE" ) ;
      meEtaPhiDepth1= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_2_HE" ) ;
      meEtaPhiDepth2= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_3_HE" ) ;
      meEtaPhiDepth3= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14); 

      sprintf (histo, "HcalRecHitTask_eta_of_rechits_HE" ) ;
      meEta = dbe_->book1D(histo, histo, 60 , -3. , 3.);
	 
      sprintf (histo, "HcalRecHitTask_phi_of_rechits_HE" ) ;
      mePhi = dbe_->book1D(histo, histo, 72, -3.14159, 3.14159);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HE" ) ;
      meEcalHcalEnergy= dbe_->book1D(histo,histo, 50 , 0., 200.);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HE" ) ;
      meEcalHcalEnergyCone =  dbe_->book1D(histo,histo, 50 , 0., 200.);  
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HE" ) ;
      me2D= dbe_->book2D(histo, histo, 1000, -5., 95.,  1100, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HE" ) ;
      me2Dprofile= dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 100.); 
            
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HE" ) ;
      meSumRecHitsEnergy= dbe_->book1D(histo,histo, 25 , -10., 160.);
      
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HE" ) ;
      meSumRecHitsEnergyCone= dbe_->book1D(histo,histo, 25 , -10., 160.);   

      sprintf (histo, "HcalRecHitTask_timing_HE" ) ;
      meTime = dbe_->book1D(histo, histo, 20000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HE" ) ;
      meRecHitsEnergy = dbe_->book1D(histo, histo, 2000 , -100. , 100.); 

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_2_HE" ) ;
      meRecHitsEnergyNoise = dbe_->book1D(histo, histo, 200 , -1. , 1.);       


      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HE");
      meRecHitSimHit = dbe_->book2D(histo, histo, 1000, 0.,0.9,  1000, 0., 150.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HE");
      meRecHitSimHitProfile = dbe_->bookProfile(histo, histo, 100, 0.,0.9,  1000, 0., 150.);  
   

      sprintf (histo, "HcalRecHitTask_energy_hcal_vs_ecal_HE");
      meEnergyHcalVsEcal = dbe_->book2D(histo, histo, 1500, 0.,150.,  1500, 0., 150.);
      
      sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HE");
      meNumEcalRecHitsCone = dbe_->book1D(histo, histo,   3000, 0., 300.);   

 
    }
  
    // ********************** HF ************************************
    if (hcalselector_ == "HF" ){
      sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HF" ) ;
      meNumRecHitsCone    = dbe_->book1D(histo, histo, 20, 0 , 20.);

      sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HF");
      meNumRecHitsThresh = dbe_->book1D(histo, histo,   30, 0., 30.);         
      
      sprintf (histo, "HcalRecHitTask_number_of_rechits_HF" ) ;
      meNumRecHits    = dbe_->book1D(histo, histo, 20, 0 , 20.);

      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_0_HF" ) ;
      meEtaPhiDepth0= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_1_HF" ) ;
      meEtaPhiDepth1= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_2_HF" ) ;
      meEtaPhiDepth2= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_3_HF" ) ;
      meEtaPhiDepth3= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14); 

  
      sprintf (histo, "HcalRecHitTask_eta_of_rechits_HF" ) ;
      meEta = dbe_->book1D(histo, histo, 80, -5. , 5.);
	 
      sprintf (histo, "HcalRecHitTask_phi_of_rechits_HF" ) ;
      mePhi = dbe_->book1D(histo, histo, 72, -3.14159, 3.14159);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HF" ) ;
      meEcalHcalEnergy= dbe_->book1D(histo,histo, 50 , -10., 200.);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HF" ) ;
      meEcalHcalEnergyCone =  dbe_->book1D(histo,histo, 50 , -10., 200.);  
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HF" ) ;
      me2D= dbe_->book2D(histo, histo, 1000, -5., 95.,  10000, -10., 1700.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HF" ) ;
      me2Dprofile= dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 1700.); 
            
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HF" ) ;
      meSumRecHitsEnergy= dbe_->book1D(histo,histo, 50 , -10., 200.);

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_2_HF" ) ;
      meRecHitsEnergyNoise = dbe_->book1D(histo, histo, 1000 , -1. , 1.);       
      
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HF" ) ;
      meSumRecHitsEnergyCone= dbe_->book1D(histo,histo, 50 , -10., 150.);   

      sprintf (histo, "HcalRecHitTask_timing_HF" ) ;
      meTime = dbe_->book1D(histo, histo, 20000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HF" ) ;
      meRecHitsEnergy = dbe_->book1D(histo, histo, 20000 , -100. , 100.); 

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HF");
      meRecHitSimHit = dbe_->book2D(histo, histo, 1000, 0.,60.,  100, 0., 140.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HF");
      meRecHitSimHitProfile = dbe_->bookProfile(histo, histo, 100, 0.,60.,  1000, 0., 1000.);  
   
      sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HF");
      meNumEcalRecHitsCone = dbe_->book1D(histo, histo,   300, 0., 300.);   
    }

 
  
    // ************** HO   **********************************
    if (hcalselector_ == "HO" ){
      
      sprintf (histo, "HcalRecHitTask_number_of_rechits_in_cone_HO" ) ;
      meNumRecHitsCone    = dbe_->book1D(histo, histo, 50, 0 , 50.);

      sprintf (histo, "HcalRecHitTask_number_of_rechits_above_1GeV_HO");
      meNumRecHitsThresh = dbe_->book1D(histo, histo,   30, 0., 30.);         

      sprintf (histo, "HcalRecHitTask_number_of_rechits_HO" ) ;
      meNumRecHits    = dbe_->book1D(histo, histo, 70, 0 , 70.);

      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_0_HO" ) ;
      meEtaPhiDepth0= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_1_HO" ) ;
      meEtaPhiDepth1= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_2_HO" ) ;
      meEtaPhiDepth2= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14);   
	
      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_3_HO" ) ;
      meEtaPhiDepth3= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14); 

      sprintf (histo, "HcalRecHitTask_eta_vs_phi_depth_4_HO" ) ;
      meEtaPhiDepth4= dbe_->book2D(histo, histo, 500, -5., 5.,  500, -3.14, 3.14); 

      sprintf (histo, "HcalRecHitTask_eta_of_rechits_HO" ) ;
      meEta = dbe_->book1D(histo, histo, 40, -1.74 , 1.74);
	 
      sprintf (histo, "HcalRecHitTask_phi_of_rechits_HO" ) ;
      mePhi = dbe_->book1D(histo, histo, 72, -3.14159, 3.14159);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_HO" ) ;
      meEcalHcalEnergy= dbe_->book1D(histo,histo, 35 , -10., 60.);
      
      sprintf (histo, "HcalRecHitTask_energy_ecal_plus_hcal_in_cone_HO" ) ;
      meEcalHcalEnergyCone =  dbe_->book1D(histo,histo, 35 , -10., 60.);  
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_HO" ) ;
      me2D= dbe_->book2D(histo, histo, 1000, -5., 95.,  1100, -10., 100.);
      
      sprintf (histo, "HcalRecHitTask_timing_vs_energy_profile_HO" ) ;
      me2Dprofile= dbe_->bookProfile(histo, histo, 100, -5., 95.,  100, -10., 100.); 
      
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_HO" ) ;
      meSumRecHitsEnergy= dbe_->book1D(histo,histo, 50 , -10., 150.);

      sprintf (histo, "HcalRecHitTask_energy_of_rechits_2_HO" ) ;
      meRecHitsEnergyNoise = dbe_->book1D(histo, histo, 200 , -1. , 1.);       
      
      sprintf (histo, "HcalRecHitTask_sum_of_rechits_energy_in_cone_HO" ) ;
      meSumRecHitsEnergyCone= dbe_->book1D(histo,histo, 50 , -10., 150.);   

      sprintf (histo, "HcalRecHitTask_timing_HO" ) ;
      meTime = dbe_->book1D(histo, histo, 20000 , -100. , 100.); 
      
      sprintf (histo, "HcalRecHitTask_energy_of_rechits_HO" ) ;
      meRecHitsEnergy = dbe_->book1D(histo, histo, 2000 , -100. , 100.); 

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_HO");
      meRecHitSimHit = dbe_->book2D(histo, histo, 1000, 0.,1.2,  1000, 0., 150.);

      sprintf (histo, "HcalRecHitTask_energy_rechits_vs_simhits_profile_HO");
      meRecHitSimHitProfile = dbe_->bookProfile(histo, histo, 100, 0.,1.1,  1000, 0., 150.);  
  
      sprintf (histo, "HcalRecHitTask_number_of_ecalrechits_in_cone_HO");
      meNumEcalRecHitsCone = dbe_->book1D(histo, histo,   300, 0., 300.);   


    }

  }
}

HcalRecHitsValidation::~HcalRecHitsValidation() {
   
  std::cout << " outputFile_.size() =  " << outputFile_.size() << std::endl;
  std::cout << " dbe_ = " << dbe_ << std::endl;
  if ( outputFile_.size() != 0 && dbe_ ) dbe_->save(outputFile_);
  
}

void HcalRecHitsValidation::endJob() {
  
  std::cout << " outputFile_.size() =  " << outputFile_.size() << std::endl;
  std::cout << " dbe_ = " << dbe_ << std::endl; 
  if ( outputFile_.size() != 0 && dbe_ ) dbe_->save(outputFile_);
  
}
void HcalRecHitsValidation::beginJob(const edm::EventSetup& c){

}
void HcalRecHitsValidation::analyze(edm::Event const& e, edm::EventSetup const& c) {

  int subdet = 1;
  // energy in HCAL
  Double_t eHcal = 0.;
  // energy in cone HCAL 
  Double_t eHcalCone = 0.;  

  // energy in ECAL
  Double_t eEcal = 0.;
  // energy in coneECAL
  Double_t eEcalCone = 0.;

  // energy, eta and phi for most energetic HCAL crystal
  Double_t maxEnergyHcal = 0.;
  Double_t maxPhi=-1000.;
  Double_t maxEta=-1000.;
  
  // Total numbet of RecHits in HCAL
  Int_t nrechits = 0;
  // Number of rechits in HCAL in the cone
  Int_t nrechitsCone = 0;
  // Number of rechits in HCAL above 1GeV 
  Int_t nrechitsThresh = 0;


      
  if (hcalselector_ == "HB"  ) subdet = 1;
  if (hcalselector_ == "HE"  ) subdet = 2;
  if (hcalselector_ == "HO"  ) subdet = 3;
  if (hcalselector_ == "HF"  ) subdet = 4;
  
  c.get<IdealGeometryRecord>().get (geometry);

  using namespace edm;
 
  
  if (hcalselector_ == "noise")
    {
      std::vector<edm::Handle<HBHERecHitCollection> > hbhecoll;
      e.getManyByType(hbhecoll);
      std::vector<edm::Handle<HBHERecHitCollection> >::iterator i;
      
      for (i=hbhecoll.begin(); i!=hbhecoll.end(); i++)
	{
	  
	  for (HBHERecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
	    {
	      HcalDetId cell(j->id());
	      double e = j->energy();
	      
	      if (cell.subdet() == 1)           // HB
		{
		  e_hb->Fill(Double_t(e));
		  
		  //  std::cout << "RecHit energy = " <<  j->energy() << std::endl;
		}
	      else { e_he->Fill(Double_t(e)); } // HE
	  
	    }
	}
      

      std::vector<edm::Handle<HFRecHitCollection> > hfcoll;
      e.getManyByType(hfcoll);
      std::vector<edm::Handle<HFRecHitCollection> >::iterator ihf;
  
      for (ihf=hfcoll.begin(); ihf!=hfcoll.end(); ihf++)
	{      
	  for (HFRecHitCollection::const_iterator j=(*ihf)->begin(); j!=(*ihf)->end(); j++)
	    {

	      HcalDetId cell(j->id());
	      int depth = cell.depth();
	      double e  = j->energy();
	      //	  std::cout << "RecHit energy = " <<  j->energy() << std::endl;
	  
	      if(depth == 1)  
		e_hfl->Fill(Double_t(e));  
	      else 
		e_hfs->Fill(Double_t(e));  
          
	    }
	}
  
      std::vector<edm::Handle<HORecHitCollection> > hocoll;
      e.getManyByType(hocoll);
      std::vector<edm::Handle<HORecHitCollection> >::iterator iho;
  
      for (iho=hocoll.begin(); iho!=hocoll.end(); iho++)
	{
      
	  for (HORecHitCollection::const_iterator j=(*iho)->begin(); j!=(*iho)->end(); j++)
	    {
	      HcalDetId cell(j->id());
	      double e = j->energy();
	  
	      //	 std::cout << "RecHit energy = " <<  j->energy() << std::endl;
	
	      e_ho->Fill(Double_t(e));  
          
	    }
	} 


    }
  else
    {
      if (hcalselector_ == "HO")
	{
	  std::vector<edm::Handle<HBHERecHitCollection> > colls;
	  e.getManyByType(colls);
	  std::vector<edm::Handle<HBHERecHitCollection> >::iterator i;
      
	  for (i=colls.begin(); i!=colls.end(); i++) 
	    {
	  
	      for (HBHERecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
		  HcalDetId cell(j->id());
		  // We are looking for maximum for HO in HB region
		  if (cell.subdet() == 1)
		    {

		      const CaloCellGeometry* cellGeometry =
			geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		      double fEta = cellGeometry->getPosition().eta () ;
		      double fPhi = cellGeometry->getPosition().phi () ;
		      if ( (j->energy()) > maxEnergyHcal ) 
			{
			  maxEnergyHcal = j->energy();
			  maxPhi = fPhi;
			  maxEta = fEta;
			}
		    }
		}
	    }
	}

  


      if (hcalselector_ == "HB" || hcalselector_ == "HE" )
	{
	  std::vector<edm::Handle<HBHERecHitCollection> > colls;
	  e.getManyByType(colls);
	  std::vector<edm::Handle<HBHERecHitCollection> >::iterator i;
      
	  for (i=colls.begin(); i!=colls.end(); i++) 
	    {
	  
	      for (HBHERecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
		  HcalDetId cell(j->id());
		  if (cell.subdet() == subdet)
		    {

		      const CaloCellGeometry* cellGeometry =
			geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		      double fEta = cellGeometry->getPosition().eta () ;
		      double fPhi = cellGeometry->getPosition().phi () ;
		      if ( (j->energy()) > maxEnergyHcal ) 
			{
			  maxEnergyHcal = j->energy();
			  maxPhi = fPhi;
			  maxEta = fEta;
			}
		    }
		}


	      for (HBHERecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
	      
		  HcalDetId cell(j->id());
		  if (cell.subdet() == subdet)
		    {
		      nrechits++;

		      Int_t depth = cell.depth();
		      const CaloCellGeometry* cellGeometry =
			geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		      double fEta = cellGeometry->getPosition().eta () ;
		      double fPhi = cellGeometry->getPosition().phi () ;
		      meEta -> Fill(fEta);
		      mePhi -> Fill(fPhi);

		      Double_t PI = 3.141592653589;
		      float deltaphi= maxPhi-fPhi;
		      if (fPhi>maxPhi) { deltaphi= fPhi - maxPhi;}
		      if (deltaphi>PI) {deltaphi=2*PI-deltaphi;}
		      float deltaeta = fEta - maxEta;
		      Double_t r = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);


		      if (depth == 0)
			meEtaPhiDepth0->Fill(fEta, fPhi);
		      if (depth == 1)
			meEtaPhiDepth1->Fill(fEta, fPhi);
		      if (depth == 2)
			meEtaPhiDepth2->Fill(fEta, fPhi);
		      if (depth == 3)
			meEtaPhiDepth3->Fill(fEta, fPhi);
		      if (depth == 4)
			meEtaPhiDepth4->Fill(fEta, fPhi);
		  
		      meTime->Fill(j->time());
		      Double_t eRHhcal =  j->energy();
		      meRecHitsEnergy->Fill(eRHhcal);
		      meRecHitsEnergyNoise->Fill(eRHhcal);

		      eHcal += eRHhcal;
		 
		      if( r<0.3){
			eHcalCone += eRHhcal;
			nrechitsCone++;
		      }
		  
		      if(eRHhcal>1.) nrechitsThresh++;
		  
		      me2D->Fill( eRHhcal,  j->time() );
		      me2Dprofile->Fill(eRHhcal,j->time() );
		    }
	      
		}
	    }
	}
 

      if (hcalselector_ == "HF")
	{
      
	  std::vector<edm::Handle<HFRecHitCollection> > colls;
	  e.getManyByType(colls);
	  std::vector<edm::Handle<HFRecHitCollection> >::iterator i;
	  for (i=colls.begin(); i!=colls.end(); i++) 
	    {


	      for (HFRecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
		  HcalDetId cell(j->id());
	     
		  const CaloCellGeometry* cellGeometry =
		    geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		  double fEta = cellGeometry->getPosition().eta () ;
		  double fPhi = cellGeometry->getPosition().phi () ;
		  if ( (j->energy()) > maxEnergyHcal ) 
		    {
		      maxEnergyHcal = j->energy();
		      maxPhi = fPhi;
		      maxEta = fEta;
		    }		
		}


	  
	      for (HFRecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
		  nrechits++;

		  HcalDetId cell(j->id());
		  Int_t depth = cell.depth();
		  const CaloCellGeometry* cellGeometry =
		    geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		  double fEta = cellGeometry->getPosition().eta () ;
		  double fPhi = cellGeometry->getPosition().phi () ;
		  meEta -> Fill(fEta);
		  mePhi -> Fill(fPhi);

		  Double_t PI = 3.141592653589;
		  float deltaphi= maxPhi-fPhi;
		  if (fPhi>maxPhi) { deltaphi= fPhi - maxPhi;}
		  if (deltaphi>PI) {deltaphi=2*PI-deltaphi;}
		  float deltaeta = fEta - maxEta;
		  Double_t r = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);
	     
		  if (depth == 0)
		    meEtaPhiDepth0->Fill(fEta, fPhi);
		  if (depth == 1)
		    meEtaPhiDepth1->Fill(fEta, fPhi);
		  if (depth == 2)
		    meEtaPhiDepth2->Fill(fEta, fPhi);
		  if (depth == 3)
		    meEtaPhiDepth3->Fill(fEta, fPhi);
		  if (depth == 4)
		    meEtaPhiDepth4->Fill(fEta, fPhi);

		  meTime->Fill(j->time());
		  Double_t eRHhcal =  j->energy();
		  meRecHitsEnergy->Fill(eRHhcal);
		  meRecHitsEnergyNoise->Fill(eRHhcal);
	       
	      
		  eHcal += eRHhcal;
	      
		  if( r<0.3){
		    eHcalCone += eRHhcal;
		    nrechitsCone++;
		  }


		  if(eRHhcal>1.) nrechitsThresh++;

		  me2D->Fill( eRHhcal,  j->time() );
		  me2Dprofile->Fill(eRHhcal,j->time() );

	      
		}
	  
	    }
	  
	}
 
      if (hcalselector_ == "HO")
	{

	  std::vector<edm::Handle<HORecHitCollection> > colls;
	  e.getManyByType(colls);
	  std::vector<edm::Handle<HORecHitCollection> >::iterator i;
	  for (i=colls.begin(); i!=colls.end(); i++) 
	    {
	 
	      for (HORecHitCollection::const_iterator j=(*i)->begin(); j!=(*i)->end(); j++)
		{
	      
		  HcalDetId cell(j->id());
		  if (cell.subdet() == subdet)
		    {
		      nrechits++;
		      Int_t depth = cell.depth();
		      const CaloCellGeometry* cellGeometry =
			geometry->getSubdetectorGeometry (cell)->getGeometry (cell) ;
		      double fEta = cellGeometry->getPosition().eta () ;
		      double fPhi = cellGeometry->getPosition().phi () ;
		      meEta -> Fill(fEta);
		      mePhi -> Fill(fPhi);
		      Double_t PI = 3.141592653589;
		      float deltaphi= maxPhi-fPhi;
		      if (fPhi>maxPhi) { deltaphi= fPhi - maxPhi;}
		      if (deltaphi>PI) {deltaphi=2*PI-deltaphi;}
		      float deltaeta = fEta - maxEta;
		      Double_t r = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);


		      if (depth == 0)
			meEtaPhiDepth0->Fill(fEta, fPhi);
		      if (depth == 1)
			meEtaPhiDepth1->Fill(fEta, fPhi);
		      if (depth == 2)
			meEtaPhiDepth2->Fill(fEta, fPhi);
		      if (depth == 3)
			meEtaPhiDepth3->Fill(fEta, fPhi);
		      if (depth == 4)
			meEtaPhiDepth4->Fill(fEta, fPhi);
		  
		  
		      meTime->Fill(j->time());
		      Double_t eRHhcal =  j->energy();
		      meRecHitsEnergy->Fill(eRHhcal);
		      meRecHitsEnergyNoise->Fill(eRHhcal);



		      eHcal += eRHhcal;
		  
		      if( r<0.3){
			eHcalCone += eRHhcal;
			nrechitsCone++;
		      }

		      if(eRHhcal>1.) nrechitsThresh++;

		      me2D->Fill( eRHhcal,  j->time() );
		      me2Dprofile->Fill(eRHhcal,j->time() );
		    }
      
		}
	    }
	}
 
      meSumRecHitsEnergy ->Fill( eHcal );

      meSumRecHitsEnergyCone ->Fill(eHcalCone);



      meNumRecHits->Fill(nrechits);
      meNumRecHitsCone->Fill(nrechitsCone);
      meNumRecHitsThresh->Fill(nrechitsThresh);

      // Getting Ecal EB and EE Rechits 
      Int_t numrechitsEcal = 0;
      if (hcalselector_ == "HB"){
	Handle<EBRecHitCollection> EcalRecHitEB;
    
	e.getByLabel( "ecalRecHit" ,"EcalRecHitsEB" , EcalRecHitEB);
    
	const EBRecHitCollection *EBRecHit = EcalRecHitEB.product();
	
	for (EcalRecHitCollection::const_iterator RecHit = EBRecHit->begin(); RecHit != EBRecHit->end() ; ++RecHit)
	  {
	    EBDetId EBid = EBDetId(RecHit->id());
	    
	    const CaloCellGeometry* cellGeometry =
	      geometry->getSubdetectorGeometry (EBid)->getGeometry (EBid) ;
	    double fEta = cellGeometry->getPosition ().eta () ;
	    double fPhi = cellGeometry->getPosition ().phi () ;
	    
	    Double_t PI = 3.141592653589;
	    float deltaphi= maxPhi-fPhi;
	    if (fPhi>maxPhi) { deltaphi= fPhi - maxPhi;}
	    if (deltaphi>PI) {deltaphi=2*PI-deltaphi;}
	    float deltaeta = fEta - maxEta;
	    Double_t r = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);


	    eEcal += RecHit->energy();

	    if (r<0.3){
	      Double_t energy = RecHit->energy();
	      numrechitsEcal++;
	      eEcalCone +=  energy;
	    }
	  }
      }
      

      if (hcalselector_ == "HE"){
	Handle<EERecHitCollection> EcalRecHitEE;
    
	e.getByLabel( "ecalRecHit" ,"EcalRecHitsEE" , EcalRecHitEE);
    
	const EERecHitCollection *EERecHit = EcalRecHitEE.product();
    
	for (EcalRecHitCollection::const_iterator RecHit = EERecHit->begin(); RecHit != EERecHit->end() ; ++RecHit)
	  {
	    EEDetId EEid = EEDetId(RecHit->id());
	
	    const CaloCellGeometry* cellGeometry =
	      geometry->getSubdetectorGeometry (EEid)->getGeometry (EEid) ;
	    double fEta = cellGeometry->getPosition ().eta () ;
	    double fPhi = cellGeometry->getPosition ().phi () ;
	
	    Double_t PI = 3.141592653589;
	    float deltaphi= maxPhi-fPhi;
	    if (fPhi>maxPhi) { deltaphi= fPhi - maxPhi;}
	    if (deltaphi>PI) {deltaphi=2*PI-deltaphi;}
	    float deltaeta = fEta - maxEta;
	    Double_t r = sqrt(deltaeta* deltaeta + deltaphi*deltaphi);
	
	    eEcal +=  RecHit->energy();
	
	    if (r<0.3){
	      Double_t energy = RecHit->energy();	
	  
	      eEcalCone +=  energy;
	 
	    }
	  }
      }
      


      meEcalHcalEnergy->Fill(eEcal+eHcal);
      meEcalHcalEnergyCone->Fill(eEcalCone+eHcalCone);
      meNumEcalRecHitsCone->Fill(numrechitsEcal);


      // Getting SimHits
      edm::Handle<PCaloHitContainer> hcalHits ;
      // e.getByLabel("SimG4Object","HcalHits",hcalHits);

      e.getByLabel("g4SimHits","HcalHits",hcalHits);
      const PCaloHitContainer * SimHitResult = hcalHits.product () ;
  
      float fEnergySimHits = 0;
      // sum of subdet SimHits.
  
      for (std::vector<PCaloHit>::const_iterator SimHits = SimHitResult->begin () ;
	   SimHits != SimHitResult->end() ;
	   ++SimHits)
	{
	  HcalDetId detId(SimHits->id());
	  if (subdet == detId.subdet())
	    {
	      fEnergySimHits += SimHits->energy();
	    }
	}
  

      meRecHitSimHit->Fill( fEnergySimHits,eHcalCone );
      meRecHitSimHitProfile->Fill( fEnergySimHits,eHcalCone);

      if (hcalselector_=="HE" || hcalselector_=="HB")  
	{
	  meEnergyHcalVsEcal -> Fill(eEcalCone,eHcalCone);
	}
    }

}
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(HcalRecHitsValidation);

