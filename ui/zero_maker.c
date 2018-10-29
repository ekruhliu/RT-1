/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:23:43 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:23:44 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	zero_maker(t_scene *sc)
{
	sc->filters->sepia_on = 0;
	sc->filters->b_w_on = 0;
	sc->filters->blood_on = 0;
	sc->filters->bt_on = 0;
	sc->filters->gt_on = 0;
	sc->filters->negative_on = 0;
	sc->filters->gradient = 0;
}
