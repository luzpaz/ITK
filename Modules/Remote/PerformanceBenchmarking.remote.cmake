#-- # Grading Level Criteria Report
#-- EVALUATION DATE: 2020-03-01
#-- EVALUATORS: [<<NO EVALUATOR>>,<<NO EVALUATOR>>]
#--
#-- ## Compliance level 5 star (AKA ITK main modules, or remote modules that could become core modules)
#--   - [ ] Widespread community dependence
#--   - [ ] Above 90% code coverage
#--   - [ ] CI dashboards and testing monitored rigorously
#--   - [ ] Key API features are exposed in wrapping interface
#--   - [ ] All requirements of Levels 4,3,2,1
#--
#-- ## Compliance Level 4 star (Very high-quality code, perhaps small community dependence)
#--   - [ ] Meets all ITK code style standards
#--   - [ ] No external requirements beyond those needed by ITK proper
#--   - [ ] Builds and passes tests on all supported platforms within 1 month of each core tagged release
#--            - [ ] Windows Shared Library Build with Visual Studio
#--            - [ ] Mac with clang compiler
#--            - [ ] Linux with gcc compiler
#--   - [ ] Active developer community dedicated to maintaining code-base
#--   - [ ] 75% code coverage demonstrated for testing suite
#--   - [ ] Continuous integration testing performed
#--   - [ ] All requirements of Levels 3,2,1
#--
#-- ## Compliance Level 3 star (Quality beta code)
#--   - [ ] API | executable interface is considered mostly stable and feature complete
#--   - [ ] 10% C0-code coverage demonstrated for testing suite
#--   - [ ] Some tests exist and pass on at least some platform
#--   - [X] All requirements of Levels 2,1
#--
#-- ## Compliance Level 2 star (Alpha code feature API development or niche community/execution environment dependence )
#--   - [X] Compiles for at least 1 niche set of execution environments, and perhaps others
#--         (may depend on specific external tools like a java environment, or specific external libraries to work )
#--   - [X] All requirements of Levels 1
#--
#-- ## Compliance Level 1 star (Pre-alpha features under development and code of unknown quality)
#--   - [X] Code complies on at least 1 platform
#--
#-- ## Compliance Level 0 star ( Code/Feature of known poor-quality or deprecated status )
#--   - [ ] Code reviewed and explicitly identified as not recommended for use
#--
#-- ### Please document here any justification for the criteria above
#       Code style enforced by clang-format on 2020-02-19, and clang-tidy modernizations completed

# Contact: Matt McCormick <matt.mccormick@kitware.com>
itk_fetch_module(
  PerformanceBenchmarking
  "New classes increase operating system process priority to
minimize the impact of other processes running on the system.

These classes are used by a suite of example ITK benchmarks to
quantify toolkit performance.

For more information, see::

  McCormick M., Kang H.J., Barre S.
  Performance Benchmarking the Insight Toolkit
  The Insight Journal. January-December. 2016.
  https://doi.org/10.54294/9feae9
"
  MODULE_COMPLIANCE_LEVEL 2
  GIT_REPOSITORY https://github.com/InsightSoftwareConsortium/ITKPerformanceBenchmarking.git
  GIT_TAG 6c7c21413da6c0760b86ed28513d404bb5a347de
  )
