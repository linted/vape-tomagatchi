add_executable(${PROJECT_NAME}
    main.c
    stm32f0xx_hal_msp.c
    stm32f0xx_it.c
    system_stm32f0xx.c
    tomagatchi.c
)

target_compile_options(${PROJECT_NAME} PUBLIC "-static")
target_link_options(${PROJECT_NAME} PUBLIC "-static")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC stm32f0xx_hal freertos_kernel freertos_config) 
