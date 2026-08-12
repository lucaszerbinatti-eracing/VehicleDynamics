###########################################################################
## Makefile generated for component 'PlanarModelandControl'. 
## 
## Makefile     : PlanarModelandControl.mk
## Generated on : Tue Aug 11 13:44:11 2026
## Final product: ./PlanarModelandControl
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = PlanarModelandControl
MAKEFILE                  = PlanarModelandControl.mk
MATLAB_ROOT               = /home/lucaspz/MATLAB
MATLAB_BIN                = /home/lucaspz/MATLAB/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/lucaspz/Projetos/CodeGeneration/VehicleDynamics
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++11
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2026a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

FORMAT_FOR_ECHO_SH               = ""'$1'
FORMAT_FOR_ECHO                  = $(FORMAT_FOR_ECHO_SH)
HASH                             = \#
SEMICOLON                        = ;
OPEN_PAREN                       = (
CLOSE_PAREN                      = )
ESCAPE_SPECIAL_CHARS             = $(strip $(subst $(CLOSE_PAREN),\$(CLOSE_PAREN),\
	$(subst $(OPEN_PAREN),\$(OPEN_PAREN),\
	$(subst &,\&,\
	$(subst ~,\~,\
	$(subst ?,\?,\
	$(subst *,\*,\
	$(subst },\},\
	$(subst {,\{,\
	$(subst >,\>,\
	$(subst <,\<,\
	$(subst !,\!,\
	$(subst ],\],\
	$(subst [,\[,\
	$(subst $(HASH),\$(HASH),\
	$(subst \\,\\\,\
	$(subst ',\',\
	$(subst ",\",\
	$1))))))))))))))))))

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O0
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./PlanarModelandControl
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/PlanarModelandControl_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/PlanarModelandControl_ert_rtw/sil -I$(START_DIR)/PlanarModelandControl_ert_rtw/coderassumptions -I$(MATLAB_ROOT)/toolbox/rtw/targets/pil/c -I$(MATLAB_ROOT)/extern/include/coder/connectivity/XILTgtAppSvc -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/connectivity/src/XilHostTgtCommon -I$(MATLAB_ROOT)/extern/include/coder/connectivity/CoderAssumpTgtAppSvc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DCODER_ASSUMPTIONS_ENABLED=1 -DXIL_SIGNAL_HANDLER=1 -DSIL_DISABLE_SUBNORMAL_SUPPORT=0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1 -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=50000 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=50000 -DMEM_UNIT_BYTES=1 -DMemUnit_T=uint8_T
DEFINES_STANDARD = -DMODEL=PlanarModelandControl -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/PlanarModelandControl_ert_rtw/sil/xil_interface.cpp $(START_DIR)/PlanarModelandControl_ert_rtw/sil/sil_main.cpp $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_interface_lib.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_data_stream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_services.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xilcomms_rtiostream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/target_io.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/cpp/coder_assumptions_app.cpp $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_data_stream.c $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_rtiostream.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xil_interface.o sil_main.o rtiostream_tcpip.o xil_interface_lib.o xil_data_stream.o xil_services.o xilcomms_rtiostream.o xil_rtiostream.o rtiostream_utils.o target_io.o coder_assumptions_app.o coder_assumptions_data_stream.o coder_assumptions_rtiostream.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

MODELREF_LIBS = ../PlanarModelandControl.o ../PlanarModelandControl_capi.o ../PlanarModelandControl_data.o

LIBS = $(START_DIR)/PlanarModelandControl_ert_rtw/coderassumptions/lib/PlanarModelandControl_ca.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


prebuild : 


download : $(PRODUCT)


execute : download
	@echo $(call FORMAT_FOR_ECHO,### Invoking postbuild tool Execute ...)
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo $(call FORMAT_FOR_ECHO,### Done invoking postbuild tool.)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MODELREF_LIBS) $(LIBS)
	@echo $(call FORMAT_FOR_ECHO,### Creating standalone executable "$(PRODUCT)" ...)
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) -Wl,--start-group ../PlanarModelandControl.o ../PlanarModelandControl_capi.o ../PlanarModelandControl_data.o $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS) -Wl,--end-group
	@echo $(call FORMAT_FOR_ECHO,### Created: "$(PRODUCT)")


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xil_interface.o : $(START_DIR)/PlanarModelandControl_ert_rtw/sil/xil_interface.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sil_main.o : $(START_DIR)/PlanarModelandControl_ert_rtw/sil/sil_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtiostream_tcpip.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_interface_lib.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_interface_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_data_stream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_data_stream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_services.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_services.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xilcomms_rtiostream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xilcomms_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xil_rtiostream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/xil_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_utils.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


target_io.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/target_io.c
	$(CC) $(CFLAGS) -o "$@" "$<"


coder_assumptions_app.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/cpp/coder_assumptions_app.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_assumptions_data_stream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_data_stream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


coder_assumptions_rtiostream.o : $(MATLAB_ROOT)/toolbox/rtw/targets/pil/c/coder_assumptions_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo $(call FORMAT_FOR_ECHO,### PRODUCT = $(PRODUCT))
	@echo $(call FORMAT_FOR_ECHO,### PRODUCT_TYPE = $(PRODUCT_TYPE))
	@echo $(call FORMAT_FOR_ECHO,### BUILD_TYPE = $(BUILD_TYPE))
	@echo $(call FORMAT_FOR_ECHO,### INCLUDES = $(INCLUDES))
	@echo $(call FORMAT_FOR_ECHO,### DEFINES = $(DEFINES))
	@echo $(call FORMAT_FOR_ECHO,### ALL_SRCS = $(ALL_SRCS))
	@echo $(call FORMAT_FOR_ECHO,### ALL_OBJS = $(ALL_OBJS))
	@echo $(call FORMAT_FOR_ECHO,### LIBS = $(LIBS))
	@echo $(call FORMAT_FOR_ECHO,### MODELREF_LIBS = $(MODELREF_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### SYSTEM_LIBS = $(SYSTEM_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### CFLAGS = $(CFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### LDFLAGS = $(LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPPFLAGS = $(CPPFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPP_LDFLAGS = $(CPP_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### ARFLAGS = $(ARFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CFLAGS = $(MEX_CFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CPPFLAGS = $(MEX_CPPFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_LDFLAGS = $(MEX_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS))
	@echo $(call FORMAT_FOR_ECHO,### EXECUTE_FLAGS = $(EXECUTE_FLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MAKE_FLAGS = $(MAKE_FLAGS))


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


