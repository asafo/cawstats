AUTOMAKE_OPTIONS = foreign subdir-objects

CPPFLAGS = -Wall -pedantic -std=c++11 -Werror
include_HEADERS = cawstats.hpp

lib_LTLIBRARIES = libcawstats.la libdefault_skin.la
libcawstats_la_SOURCES  = src/file.cpp src/section.cpp

bin_PROGRAMS = cawstats cawstats_webui
cawstats_SOURCES = cawstats.cpp
cawstats_LDADD = .libs/libcawstats.a $(DEPS_LIBS) -lcppcms -lboost_date_time

cawstats_webui_SOURCES = webui/main.cpp webui/cawstats_srv.cpp webui/rest_api.cpp
cawstats_webui_LDADD = -lcawstats $(DEPS_LIBS) -lcppcms -lboost_date_time

libdefault_skin_la_SOURCES = webui/skin/skin.cpp

webui/skin/skin.cpp: webui/view/home.tmpl
	@mkdir -p webui/skin
	cppcms_tmpl_cc webui/view/home.tmpl -o webui/skin/skin.cpp
