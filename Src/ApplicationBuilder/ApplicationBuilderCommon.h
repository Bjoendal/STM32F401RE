
#ifndef ApplicationBuilderCommon_H
#define ApplicationBuilderCommon_H

#include "types.h"
#include "stm32f4xx.h"
#include "CUart.h"
#include <CTimIrqTable.h>
#include "CGpio.h"

#include "CLed.h"
#include "CButton.h"

class ApplicationBuilderCommon
{
 

private: 
	ApplicationBuilderCommon(void);

	static ApplicationBuilderCommon _this;


public :
	static ApplicationBuilderCommon* GetApplicationBuilder();
    
    void InitRelations(void);
    BOOL Start(void);

    void Run();
private :
    volatile U32 							dummy;


    //	DEV
    CButton	itsCButton;
    CLed	itsCLed;



    //	HAL
    CUart	itsCUart;
    CGpio	itsCGpio;

public:
};

#endif  

