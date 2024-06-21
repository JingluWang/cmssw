import FWCore.ParameterSet.Config as cms

particleFlowSuperClusterHGCal = cms.EDProducer("PFECALSuperClusterProducer",
    BeamSpot = cms.InputTag("hltOnlineBeamSpot"),
    ClusteringType = cms.string('Mustache'),
    ESAssociation = cms.InputTag("particleFlowClusterECAL"),
    EnergyWeight = cms.string('Raw'),
    PFBasicClusterCollectionBarrel = cms.string('particleFlowBasicClusterECALBarrel'),
    PFBasicClusterCollectionEndcap = cms.string(''),
    PFBasicClusterCollectionPreshower = cms.string('particleFlowBasicClusterECALPreshower'),
    PFClusters = cms.InputTag("particleFlowClusterHGCal"),
    PFSuperClusterCollectionBarrel = cms.string('particleFlowSuperClusterECALBarrel'),
    PFSuperClusterCollectionEndcap = cms.string(''),
    PFSuperClusterCollectionEndcapWithPreshower = cms.string(''),
    applyCrackCorrections = cms.bool(False),
    barrelRecHits = cms.InputTag("hltEcalRecHit","EcalRecHitsEE"),
    doSatelliteClusterMerge = cms.bool(False),
    dropUnseedable = cms.bool(True),
    endcapRecHits = cms.InputTag("hltEcalRecHit","EcalRecHitsEB"),
    etawidth_SuperClusterBarrel = cms.double(0.04),
    etawidth_SuperClusterEndcap = cms.double(0.04),
    isOOTCollection = cms.bool(False),
    mightGet = cms.optional.untracked.vstring,
    phiwidth_SuperClusterBarrel = cms.double(0.6),
    phiwidth_SuperClusterEndcap = cms.double(0.6),
    regressionConfig = cms.PSet(
        applySigmaIetaIphiBug = cms.bool(False),
        eRecHitThreshold = cms.double(1),
        ecalRecHitsEB = cms.InputTag("hltEcalRecHit","EcalRecHitsEB"),
        ecalRecHitsEE = cms.InputTag("hltEcalRecHit","EcalRecHitsEE"),
        hgcalCylinderR = cms.double(2.79999995232),
        hgcalRecHits = cms.InputTag(""),
        isHLT = cms.bool(False),
        isPhaseII = cms.bool(False),
        regressionKeyEB = cms.string('pfscecal_EBCorrection_offline_v2'),
        regressionKeyEE = cms.string('pfscecal_EECorrection_offline_v2'),
        regressionMaxEB = cms.double(2),
        regressionMaxEE = cms.double(2),
        regressionMinEB = cms.double(0.2),
        regressionMinEE = cms.double(0.2),
        uncertaintyKeyEB = cms.string('pfscecal_EBUncertainty_offline_v2'),
        uncertaintyKeyEE = cms.string('pfscecal_EEUncertainty_offline_v2'),
        uncertaintyMaxEB = cms.double(0.5),
        uncertaintyMaxEE = cms.double(0.5),
        uncertaintyMinEB = cms.double(0.0002),
        uncertaintyMinEE = cms.double(0.0002),
        vertexCollection = cms.InputTag("offlinePrimaryVertices")
    ),
    satelliteClusterSeedThreshold = cms.double(50),
    satelliteMajorityFraction = cms.double(0.5),
    seedThresholdIsET = cms.bool(True),
    thresh_PFClusterBarrel = cms.double(0),
    thresh_PFClusterES = cms.double(0),
    thresh_PFClusterEndcap = cms.double(0.15),
    thresh_PFClusterSeedBarrel = cms.double(1),
    thresh_PFClusterSeedEndcap = cms.double(1),
    thresh_SCEt = cms.double(4),
    useDynamicDPhiWindow = cms.bool(True),
    useRegression = cms.bool(False),
    verbose = cms.untracked.bool(False)
)
