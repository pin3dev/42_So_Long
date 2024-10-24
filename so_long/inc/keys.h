/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:31:52 by pin3dev           #+#    #+#             */
/*   Updated: 2024/10/24 17:18:10 by pin3dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
#define KEYS_H

#ifdef __APPLE__
	#define KEY_ESC 0xff1b
	#define KEY_UP 0xff52
	#define KEY_DOWN 0xff54
	#define KEY_LEFT 0xff51
	#define KEY_RIGHT 0xff53
#else
    #include <X11/keysym.h>
    #define KEY_ESC XK_Escape
	#define KEY_UP XK_Up
    #define KEY_DOWN XK_Down
    #define KEY_LEFT XK_Left
    #define KEY_RIGHT XK_Right
#endif

#endif