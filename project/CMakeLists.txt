
PROJECT( tp_cimo )

cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

LINK_DIRECTORIES( ${binary_dir} )

# -------------------------------------------------- #
#     Source and header files                        #
# -------------------------------------------------- #

set( TPCIMO-SOURCES
	src/MetaObjetGraphique.c
	src/MetaRectangle.c
	src/MetaCercle.c
   )

set( TPCIMO-HEADERS
	src/ObjetGraphique.h
	src/Rectangle.h
	src/Cercle.h
	src/MetaObjetGraphique.h
	src/MetaRectangle.h
	src/MetaCercle.h
   )

# Add test executable target
ADD_EXECUTABLE ( tp_cimo
                 src/main.c
                 ${TPCIMO-SOURCES}
                 ${TPCIMO-HEADERS}
                )

SET_TARGET_PROPERTIES( tp_cimo PROPERTIES LINKER_LANGUAGE C )
