import FWCore.ParameterSet.Config as cms

puppiCentral = cms.VPSet(
                 cms.PSet(
                  algoId           = cms.int32(5),  #0 is default Puppi
                  useCharged       = cms.bool(True),
                  applyLowPUCorr   = cms.bool(True),
                  combOpt          = cms.int32(0),
                  cone             = cms.double(0.4),
                  rmsPtMin         = cms.double(0.1),
                  rmsScaleFactor   = cms.double(1.0)
                 )
                )

puppiForward = cms.VPSet(
                cms.PSet(
                 algoId         = cms.int32(5),  #0 is default Puppi
                 useCharged     = cms.bool(False),
                 applyLowPUCorr = cms.bool(True),
                 combOpt        = cms.int32(0),
                 cone           = cms.double(0.4),
                 rmsPtMin       = cms.double(0.5),
                 rmsScaleFactor = cms.double(1.0)
                 )
                )

# from cfipython/, generated by PuppiProducer::fillDescriptions
import CommonTools.PileupAlgos.PuppiProducer_cfi as _mod
puppi = _mod.PuppiProducer.clone(
                       EtaMinUseDeltaZ = 2.4,
                       NumOfPUVtxsForCharged = 2,
                       PtMaxCharged   = 20.,
                       PtMaxNeutralsStartSlope = 20.,
                       #candName      = cms.string('packedPFCandidates'),
                       #vertexName     = cms.string('offlineSlimmedPrimaryVertices'),
                       clonePackedCands   = False, # should only be set to True for MiniAOD
                       algos          = { 
                        0: dict( 
                         puppiAlgos = puppiCentral
                        )
                        } #only one PSet is defined in reference
)
puppi.algos.append(cms.PSet( 
                         etaMin              = cms.vdouble( 2.5,  3.0),
                         etaMax              = cms.vdouble( 3.0, 10.0),
                         ptMin               = cms.vdouble( 0.0,  0.0),
                         MinNeutralPt        = cms.vdouble( 1.7,  2.0),
                         MinNeutralPtSlope   = cms.vdouble(0.08, 0.08),
                         RMSEtaSF            = cms.vdouble(1.20, 0.95),
                         MedEtaSF            = cms.vdouble(0.90, 0.75),
                         EtaMaxExtrap        = cms.double( 2.0),
                         puppiAlgos = puppiForward
                       )
)
                       #  cms.PSet( 
                       #   etaMin = cms.double(3.0),
                       #   etaMax = cms.double(10.0),
                       #   ptMin  = cms.double(0.0),
                       #   MinNeutralPt        = cms.double(2.0),
                       #   MinNeutralPtSlope   = cms.double(0.07),
                       #   # RMSEtaSF = cms.double(1.18),
                       #   # MedEtaSF = cms.double(0.4397),                         
                       #   RMSEtaSF = cms.double(1.10),
                       #   MedEtaSF = cms.double(0.90),
                       #   EtaMaxExtrap = cms.double(2.0),
                       #   puppiAlgos = puppiForward
                       # )

from Configuration.Eras.Modifier_phase2_common_cff import phase2_common
phase2_common.toModify(
    puppi,
    EtaMinUseDeltaZ = 4.0,
    DeltaZCut = cms.double(0.1),
    algos = cms.VPSet( 
        cms.PSet( 
             etaMin = cms.vdouble(0.,  2.5),
             etaMax = cms.vdouble(2.5, 3.5),
             ptMin  = cms.vdouble(0.,  0.), #Normally 0
             MinNeutralPt   = cms.vdouble(0.2, 0.2),
             MinNeutralPtSlope   = cms.vdouble(0.015, 0.030),
             RMSEtaSF = cms.vdouble(1.0, 1.0),
             MedEtaSF = cms.vdouble(1.0, 1.0),
             EtaMaxExtrap = cms.double(2.0),
             puppiAlgos = puppiCentral
        ), cms.PSet( 
             etaMin              = cms.vdouble( 3.5),
             etaMax              = cms.vdouble(10.0),
             ptMin               = cms.vdouble( 0.), #Normally 0
             MinNeutralPt        = cms.vdouble( 2.0),
             MinNeutralPtSlope   = cms.vdouble(0.08),
             RMSEtaSF            = cms.vdouble(1.0 ),
             MedEtaSF            = cms.vdouble(0.75),
             EtaMaxExtrap        = cms.double( 2.0),
             puppiAlgos = puppiForward
       )
    )
)

puppiNoLep = puppi.clone(
    puppiNoLep = True,
    PtMaxPhotons = 20.
    )

from Configuration.ProcessModifiers.pp_on_AA_cff import pp_on_AA
pp_on_AA.toModify(puppi, algos = [])
