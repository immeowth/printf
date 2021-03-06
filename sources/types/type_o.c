/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 03:52:37 by ykirigay          #+#    #+#             */
/*   Updated: 2020/02/28 20:00:00 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info, uintmax_t number)
{
	info->plus = 0;
	info->space = 0;
	if (number == 0 && info->point == 0)
		info->hash = 0;
}

void			type_o(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	get_ui(&number, info);
	data.str = ft_uitoa_base_static(number, 8, 0);
	data.length = ft_strlen(data.str);
	data.negative = 0;
	if (data.length == 1 && info->hash == 1)
		info->precision--;
	if (number == 0 && info->point == 1 && info->precision == 0)
	{
		if (info->width == 0)
			data.str = "\0";
		else
			data.str = (info->hash == 1) ? "0" : " ";
	}
	if (info->hash == 1)
		data.prefix = (number == 0 && info->precision != 0) ? "\0" : "0";
	specs_handler(info, number);
	apply_specs(info, &data);
}
