##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Fibonacci
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/richard/workspace/TestCPP
ProjectPath            :=/home/richard/workspace/TestCPP/Fibonacci
IntermediateDirectory  :=../build-$(ConfigurationName)/Fibonacci
OutDir                 :=../build-$(ConfigurationName)/Fibonacci
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Richard
Date                   :=20/10/22
CodeLitePath           :=/home/richard/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Fibonacci/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Fibonacci/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Fibonacci"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Fibonacci"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Fibonacci/.d:
	@mkdir -p "../build-$(ConfigurationName)/Fibonacci"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(ObjectSuffix): fibonacci.cpp ../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/richard/workspace/TestCPP/Fibonacci/fibonacci.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fibonacci.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(DependSuffix): fibonacci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(DependSuffix) -MM fibonacci.cpp

../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(PreprocessSuffix): fibonacci.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Fibonacci/fibonacci.cpp$(PreprocessSuffix) fibonacci.cpp

../build-$(ConfigurationName)/Fibonacci/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Fibonacci/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/richard/workspace/TestCPP/Fibonacci/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Fibonacci/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Fibonacci/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Fibonacci/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Fibonacci/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Fibonacci/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Fibonacci//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


