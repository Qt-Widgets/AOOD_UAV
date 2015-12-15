/*
 * uavLogger.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: David
 */

#include "uavLogger.h"

uavLogger* uavLogger::single_instance = NULL;

void uavLogger::initialize( QTextEdit* text_box )
{
  if( init == false )
  {
    this->text_box = text_box;
    init = true;
  }
}

uavLogger::~uavLogger()
{
  delete single_instance;
}

uavLogger* uavLogger::getInstance()
{
  if( !single_instance )
    single_instance = new uavLogger;

  return single_instance;
}

void uavLogger::log( std::string string_to_log )
{
  text_box->moveCursor(QTextCursor::End);
  text_box->append( QString::fromStdString(string_to_log) );
  text_box->moveCursor(QTextCursor::End);
}
