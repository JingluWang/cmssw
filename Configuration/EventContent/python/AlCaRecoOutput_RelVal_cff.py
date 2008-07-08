import FWCore.ParameterSet.Config as cms

ALCARECOEventContent = cms.PSet(
	outputCommands = cms.untracked.vstring(
	'drop *',
        'keep *_ALCARECOMuAlZMuMu_*_*', 
        'keep *_muonCSCDigis_*_*', 
        'keep *_muonDTDigis_*_*', 
        'keep *_muonRPCDigis_*_*', 
        'keep *_dt1DRecHits_*_*', 
        'keep *_dt2DSegments_*_*', 
        'keep *_dt4DSegments_*_*', 
        'keep *_csc2DRecHits_*_*', 
        'keep *_cscSegments_*_*', 
        'keep *_rpcRecHits_*_*',
        'keep *_ALCARECOTkAlCosmics*_*_*', 
        'keep Si*Cluster*_*_*_*',
	'keep *_laserAlignmentT0Producer_*_*',
        'keep *_ALCARECOTkAlMuonIsolated_*_*',
        'keep *_ALCARECOTkAlJpsiMuMu_*_*',
        'keep *_ALCARECOTkAlUpsilonMuMu_*_*',
        'keep *_ALCARECOTkAlMinBias_*_*',
	'keep *_ALCARECOTkAlBeamHalo_*_*', 
        'keep *_ALCARECOMuAlBeamHalo_*_*', 
	'keep *_ALCARECOMuAlBeamHaloOverlaps_*_*',
        'keep *_ALCARECOMuAlOverlaps_*_*', 
        'keep *_ALCARECOMuAlCalIsolatedMu_*_*',
        'keep *_ALCARECOMuAlZeroFieldGlobalCosmics_*_*',
        'keep *_cosmicMuons_*_*',
        'keep *_cosmictrackfinderP5_*_*',
        'keep *_globalMuons_*_*', 
        'keep *_siStripClusters_*_*', 
        'keep *_siPixelClusters_*_*',
        'keep *_ALCARECOSiStripCalMinBias_*_*', 
        'keep *_offlineBeamSpot_*_*',
        'keep *_*_phiSymEcalRecHitsEB_*', 
        'keep *_*_phiSymEcalRecHitsEE_*',
        'keep L1GlobalTriggerReadoutRecord_hltGtDigis_*_*',
        'keep *_*_pi0EcalRecHitsEB_*',
        'keep  *_electronFilter_*_*', 
        'keep  *_alCaIsolatedElectrons_*_*', 
        'keep edmTriggerResults_TriggerResults__HLT',
        'keep HBHERecHitsSorted_hbherecoMB_*_*',
        'keep HORecHitsSorted_horecoMB_*_*',
        'keep HFRecHitsSorted_hfrecoMB_*_*',
        'keep HBHERecHitsSorted_hbherecoNoise_*_*',
        'keep HORecHitsSorted_horecoNoise_*_*',
        'keep HFRecHitsSorted_hfrecoNoise_*_*',
        'keep *_IsoProd_*_*',
        'keep *_DiJProd_*_*',
        'keep *_GammaJetProd_*_*', 
        'keep HOCalibVariabless_*_*_*',
        'keep CSCDetIdCSCWireDigiMuonDigiCollection_*_*_*', 
        'keep CSCDetIdCSCStripDigiMuonDigiCollection_*_*_*', 
        'keep DTLayerIdDTDigiMuonDigiCollection_*_*_*', 
        'keep RPCDetIdRPCDigiMuonDigiCollection_*_*_*', 
        'keep L1MuGMTCands_*_*_*', 
        'keep L1MuGMTReadoutCollection_*_*_*',
	'keep *_MEtoEDMConverter_*_*')
)
