/*
 * IORepoAbstract.h
 *
 *  Created on: May 24, 2020
 *      Author: root
 */

#ifndef IOREPOABSTRACT_H_
#define IOREPOABSTRACT_H_

class IORepoAbstract {
	public:
		/** Writes all the data to a file. */
		virtual void writeDatabase() = 0;

		/** Read all the data from a file. */
		virtual void readDatabase() = 0;

		/** Destructor. */
		virtual ~IORepoAbstract() {};
};

#endif /* IOREPOABSTRACT_H_ */
