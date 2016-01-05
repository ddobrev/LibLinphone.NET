/*
LinphoneAuthInfo.cpp
Copyright (C) 2015  Belledonne Communications, Grenoble, France
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "LinphoneAuthInfo.h"
#include "Utils.h"

using namespace System;

String^ Linphone::Core::LinphoneAuthInfo::Username::get()
{
	API_LOCK;
	return Utils::cctops(linphone_auth_info_get_username(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::Username::set(String^ username)
{
	API_LOCK;
	const char *cc = Linphone::Core::Utils::pstoccs(username);
	linphone_auth_info_set_username(this->auth_info, cc);
	delete(cc);
}

String^ Linphone::Core::LinphoneAuthInfo::UserId::get()
{
	API_LOCK;
	return Utils::cctops(linphone_auth_info_get_userid(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::UserId::set(String^ userid)
{
	API_LOCK;
	const char *cc = Linphone::Core::Utils::pstoccs(userid);
	linphone_auth_info_set_userid(this->auth_info, cc);
	delete(cc);
}

String^ Linphone::Core::LinphoneAuthInfo::Password::get()
{
	API_LOCK;
	return Utils::cctops(linphone_auth_info_get_passwd(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::Password::set(String^ password)
{
	API_LOCK;
	const char *cc = Linphone::Core::Utils::pstoccs(password);
	linphone_auth_info_set_passwd(this->auth_info, cc);
	delete(cc);
}

String^ Linphone::Core::LinphoneAuthInfo::Realm::get()
{
	API_LOCK;
	return Utils::cctops(linphone_auth_info_get_realm(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::Realm::set(String^ realm)
{
	API_LOCK;
	const char *cc = Linphone::Core::Utils::pstoccs(realm);
	linphone_auth_info_set_realm(this->auth_info, cc);
	delete(cc);
}

String^ Linphone::Core::LinphoneAuthInfo::Domain::get()
{
    API_LOCK;
    return Utils::cctops(linphone_auth_info_get_domain(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::Domain::set(String^ domain)
{
    API_LOCK;
    const char *cc = Linphone::Core::Utils::pstoccs(domain);
    linphone_auth_info_set_domain(this->auth_info, cc);
    delete(cc);
}

String^ Linphone::Core::LinphoneAuthInfo::Ha1::get()
{
	API_LOCK;
	return Utils::cctops(linphone_auth_info_get_ha1(this->auth_info));
}

void Linphone::Core::LinphoneAuthInfo::Ha1::set(String^ ha1)
{
	API_LOCK;
	const char *cc = Linphone::Core::Utils::pstoccs(ha1);
	linphone_auth_info_set_ha1(this->auth_info, cc);
	delete(cc);
}

::LinphoneAuthInfo* Linphone::Core::LinphoneAuthInfo::GetAuthInfoPtr()
{
    return this->auth_info;
}

Linphone::Core::LinphoneAuthInfo::LinphoneAuthInfo(String^ username, String^ userid, String^ password, String^ ha1, String^ realm, String^ domain)
{
	const char* cc_username = Utils::pstoccs(username);
	const char* cc_password = Utils::pstoccs(password);
	const char* cc_realm = Utils::pstoccs(realm);
	const char* cc_userid = Utils::pstoccs(userid);
	const char* cc_ha1 = Utils::pstoccs(ha1);
	const char* cc_domain = Utils::pstoccs(domain);
	this->auth_info = linphone_auth_info_new(cc_username, cc_userid, cc_password, cc_ha1, cc_realm, cc_domain);
	delete(cc_username);
	delete(cc_userid);
	delete(cc_password);
	delete(cc_ha1);
	delete(cc_realm);
	delete(cc_domain);
}

Linphone::Core::LinphoneAuthInfo::LinphoneAuthInfo(::LinphoneAuthInfo *auth_info) :
	auth_info(auth_info)
{
}

Linphone::Core::LinphoneAuthInfo::~LinphoneAuthInfo()
{
}