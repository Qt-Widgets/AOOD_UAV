/*
 * uavLogger.h
 *
 *  Created on: Dec 8, 2015
 *      Author: David
 */

#ifndef UAVLOGGER_H_
#define UAVLOGGER_H_

#include <QTextEdit>
#include <string>

///-----------------------------------------
///  This class is an example of the singleton
///  pattern. There will be only one instance
///  of the logging class. uavLogger's only
///  responsibility is to take a string and
///  send it to the output.
///-----------------------------------------
class uavLogger
{
  public:

    void initialize( QTextEdit* text_box );

    virtual ~uavLogger();

    ///-------------------------------------
    ///  This function returns the singleton
    ///  instance of the logger class.
    ///-------------------------------------
    static uavLogger* getInstance();

    void log( std::string string_to_log );

  private:

    uavLogger() { init = false;}

    static uavLogger* single_instance;

    QTextEdit* text_box;
    bool init;
};

#endif /* UAVLOGGER_H_ */
