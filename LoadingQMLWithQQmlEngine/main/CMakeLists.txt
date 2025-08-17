add_executable(${TARGET_NAME}
  src/main.cpp
  qml.qrc
)

target_include_directories(${TARGET_NAME} PUBLIC inc/)
target_link_libraries(${TARGET_NAME}
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Gui
  Qt${QT_VERSION_MAJOR}::Qml
)

include(GNUInstallDirs)
install(TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
