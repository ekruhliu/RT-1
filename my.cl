#define AMBIENT 0
#define POINT 1
#define DIRECT 2
#define PARAL 3

#define  EPS 0.001
#define SHADOW_EPS 0.05
#define GET_BIASED(current, bias) (((current)->negDot > 0) ? (current)->inter.pointOnObj + bias : (current)->inter.pointOnObj - bias)
#define GET_REFL_RAY(objNormal, rayToMirror, normalDotLight) (objNormal * (2 * normalDotLight) + rayToMirror)

#define CLIP_TOP(cosi) ((cosi) > 1 ? 1 : (cosi))
#define CLIP_DOWN(cosi) ((cosi) < -1 ? -1 : (cosi))
#define CLIP(cosi) (CLIP_DOWN(CLIP_TOP((cosi))))
#define GET_POINT_ON_RAY(t, ray, start) ((ray) * (t) + (start))

#define SPHERE 0
#define PLANE 1
#define CYLINDER 2
#define CONE 3

#define WIDTH 1000
#define HEIGHT 1000
#define FIND_EPS_MORE(t) (t > 10000 ? 100 * t : t)
#define FIND_EPS(t) (t < 1000 ? t * EPS : FIND_EPS_MORE(t))

typedef struct 	s_cl_light
{
	int			type;
	float       cosA;
	float3 		intens;
	float3	    centre;
	float3	    dir;

}				t_cl_light;

typedef struct	s_cl_object
{
	int             type;
	int             texture;
	int             texture_size;
	int             normal_map;
	int             limited;
	int			    specular;

	float 			refl;
	float 			transp;
	float 			refr;
	float			radius;
	float			sq_cos;
	float			sq_sin;

	float3		    color;
	float3			centre;
	float3			centre1;
	float3          centre2;
	float3			dir;

	float3			normal1;
	float3			normal2;
}				t_cl_object;

typedef	struct		s_filters_on
{
	int 			gradient;
	int				sepia_on;
	int				b_w_on;
	int				blood_on;
	int				bt_on;
	int				gt_on;
	int				negative_on;
}					t_filters_on;

typedef struct	s_cl_scene
{
	int                     shadow;

	__global t_cl_object	*objects;
	int			            objCnt;

	__global t_cl_light	    *lights;
	int			            lightCnt;

	float3	                *cam;

	__global int            *earth;
	__global int            *iron;
	__global int            *iron_normal;
	__global int            *earth_normal;
	__global int            *stone;
	__global int            *stone_normal;
	__global int            *perlin;
	__global int            *sun;
	__global int            *mars;
	__global int            *merc;
	__global int            *neptune;
	__global t_filters_on   *filters;
}				t_cl_scene;

typedef struct	s_cl_inter
{
	int                 cap;
	float              minT;
  float3               pointOnObj;
  float3               objNormal;
  float3               rayStart;
	__global t_cl_object *object;
}				t_cl_inter;

typedef struct s_traceState {
	float       frac;
	float3      ray;
	t_cl_inter  inter;
	float       refl;
	float       transp;
	float       negDot;
}              t_traceState;

 int	sepia(float3 color)
 {
	 float3 color2;

	color2.x = (0.393 * color.x) + (0.769 * color.y) + (0.189 * color.z);
	color2.y = (0.349 * color.x) + (0.686 * color.y) + (0.168 * color.z);
	color2.z = (0.272 * color.x) + (0.534 * color.y) + (0.131 * color.z);

	color2.x += 7;
	color2.y += 2;

	(color2.x > 255) ? color2.x = 255 : color2.x;
	(color2.y > 255) ? color2.y = 255 : color2.y;
	(color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

 int	black_and_white(float3 color)
 {
	float b_a_w;
	float3 color2;

	b_a_w = (color.x + color.y + color.z) / 3;

	color2.x = b_a_w;
	color2.y = b_a_w;
	color2.z = b_a_w;
	(color2.x > 255) ? color2.x = 255 : color2.x;
	(color2.y > 255) ? color2.y = 255 : color2.y;
	(color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

 int	blood(float3 color)
 {
	 float3 color2;

	color2.x = (color.x * 0.99) + (color.y * 0.99) + (color.z * 0.99);
	color2.y = (color.x + color.y + color.z) / 150;
	color2.z = (color.x + color.y + color.z) / 150;
	color2.x = (color2.x + color2.y + color2.z) / 3;

	(color2.x > 255) ? color2.x = 255 : color2.x;
	(color2.y > 255) ? color2.y = 255 : color2.y;
	(color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

 int	blue_theme(float3 color)
 {
	 float3 color2;

	color2.z = (color.x * 0.99) + (color.y * 0.99) + (color.z * 0.99);
	color2.y = (color.x + color.y + color.z) / 150;
	color2.x = (color.x + color.y + color.z) / 150;
	color2.z = (color2.x + color2.y + color2.z) / 3;

	(color2.x > 255) ? color2.x = 255 : color2.x;
	(color2.y > 255) ? color2.y = 255 : color2.y;
	(color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

 int	green_theme(float3 color)
 {
	 float3 color2;

	color2.y = (color.x * 0.99) + (color.y * 0.99) + (color.z * 0.99);
	color2.x = (color.x + color.y + color.z) / 150;
	color2.z = (color.x + color.y + color.z) / 150;
	color2.y = (color2.x + color2.y + color2.z) / 3;

	(color2.x > 255) ? color2.x = 255 : color2.x;
	(color2.y > 255) ? color2.y = 255 : color2.y;
	(color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

 int	negative(float3 color)
 {
	 float3 color2;

	color2.x = 255 - color.x;
	color2.y = 255 - color.y;
	color2.z = 255 - color.z;

	 (color2.x > 255) ? color2.x = 255 : color2.x;
	 (color2.y > 255) ? color2.y = 255 : color2.y;
	 (color2.z > 255) ? color2.z = 255 : color2.z;

	 return (((int)color2.x) << 16 | ((int)color2.y) << 8 | (int)color2.z);
 }

int     colorToInt(float3 color, t_cl_scene *sc)
{
	 if (sc->filters->sepia_on == 1)
		 return (sepia(color));
	 if (sc->filters->b_w_on == 1)
		 return (black_and_white(color));
	 if (sc->filters->blood_on == 1)
		 return (blood(color));
	 if (sc->filters->bt_on == 1)
		 return (blue_theme(color));
	 if (sc->filters->gt_on == 1)
		 return (green_theme(color));
	 if (sc->filters->negative_on == 1)
		 return (negative(color));
	return (((int)color.x) << 16 | ((int)color.y) << 8 | (int)color.z);
}

float3	toViewport(int x, int y, __global float3 *transp_rotate_matrix, int width, int height)
{
	float3 buff;
	float3 res;

	buff.x = (x - ((float)width / 2.0))/ (float)width;
	buff.y = (-y + ((float)height / 2.0)) / (float)height;
	buff.z = 1;

	res.x = dot(transp_rotate_matrix[0], buff);
	res.y = dot(transp_rotate_matrix[1], buff);
	res.z = dot(transp_rotate_matrix[2], buff);

	return (res);
}

void	solveEq(float3 *abc, float2 *eqRes)
{
	eqRes->x = FLT_MAX;
	eqRes->y = FLT_MAX;
	if (fabs(abc->x) < 0.00000001)
	{
		if (fabs(abc->y) > 0.0000001)
			eqRes->x = -abc->z / abc->y;
		return ;
	}
	float disc = (abc->y * abc->y) - 4 * abc->x * abc->z;
	if (disc < 0)
		return ;
	float sc_disc = sqrt(disc);
	eqRes->x = (-abc->y + sc_disc) / (abc->x + abc->x);
	eqRes->y = (-abc->y - sc_disc) / (abc->x + abc->x);
}

void	interSphere(float3 *abc, float3 *dir, __global t_cl_object *object, float3 *toCenter)
{
	abc->x = dot(*dir, *dir);
	abc->y = 2 * dot(*toCenter, *dir);
	abc->z = dot(*toCenter, *toCenter) - (object->radius * object->radius);
}

void    interPlaneByPointAndDir(float3 *abc, float3 *from, \
									float3 *rayDir, float3 point, float3 planeDir)
{
	abc->x = 0;
	abc->y = dot(*rayDir, planeDir);
	abc->z = dot(*from - point, planeDir);
}

void	interPlane(float3 *abc, float3 *from, float3 *dir, __global t_cl_object *object)
{
	interPlaneByPointAndDir(abc, from, dir, object->centre, object->dir);
}

void	interCylinder(float3 *abc, float3 *from, float3 *dir, __global t_cl_object *object, float3 *toCenter)
{
	float3 forA;
	float3 forC;

	forA = *dir - (dot(*dir, object->dir) * object->dir);
	forC = *toCenter - (dot(*toCenter, object->dir) * object->dir);

	abc->y = 2 * dot(forA, forC);
	abc->x = dot(forA, forA);
	abc->z = dot(forC, forC) - object->radius * object->radius;
}

void	interCone(float3 *abc, float3 *from, float3 *dir, __global t_cl_object *object, float3 *toCenter)
{
	float3 forA;
	float3 forC;

	float ray_dir_dot_conic_dir;
	float toCenter_dot_dir;

	ray_dir_dot_conic_dir = dot(*dir, object->dir);
	toCenter_dot_dir = dot(*toCenter, object->dir);


	forA = *dir - (ray_dir_dot_conic_dir * object->dir);
	forC = *toCenter - object->dir * toCenter_dot_dir;

	abc->x = dot(forA, forA) * object->sq_cos - ray_dir_dot_conic_dir * ray_dir_dot_conic_dir * object->sq_sin;

	abc->y = 2 * (dot(forA, forC) * object->sq_cos - toCenter_dot_dir * ray_dir_dot_conic_dir * object->sq_sin);

	abc->z = dot(forC, forC) * object->sq_cos - toCenter_dot_dir * toCenter_dot_dir * object->sq_sin;

}

float3 getRefrRay(float3 *objNormal, float refr, float3 *rayDir, float normalDotLight)
{
	float   nR;
	int     flag = 0;
	float   k;

	if (normalDotLight < 0) {
		nR = refr;
		flag = 1;
	}
	else {
		normalDotLight = -normalDotLight;
		nR = 1 / refr;
	}
	k = 1 - nR * nR * (1 - normalDotLight * normalDotLight);
	if (k < 0)
		return (0);
	return (nR * (*rayDir) + (flag ? (*objNormal) * (nR * normalDotLight + sqrt(k)) :
								-(*objNormal) * (nR * normalDotLight + sqrt(k))));
}

void fresnel(float *refl, float *transp, float refr, float normalDotLight) {
	float etai;
	float etat;
	float k;
	float sint;
	float tempRefl;

	if (normalDotLight > 0) {
		etai = 1;
		etat = refr;
	}
	else {
		etai = refr;
		etat = 1;
	}
	k = 1 - normalDotLight * normalDotLight;
	k = k < 0 ? 0 : k;
	sint = etai / etat * sqrt(k);
	if (sint > 1) {
		*refl = *transp;
		*transp = 0;
	}
	float cost = 1 - sint * sint;
	cost = cost > 0 ? cost : 0;
	cost = sqrt(cost);
	normalDotLight = fabs(normalDotLight);
	float rs = ((etat * normalDotLight) - (etai * cost)) / ((etat * normalDotLight) + (etai * cost));
	float rp = ((etai * normalDotLight) - (etat * cost)) / ((etai * normalDotLight) + (etat * cost));
	tempRefl = *transp * (rs * rs + rp * rp) / 2;

	*refl += tempRefl;
	*transp = *transp - tempRefl;

	if (*transp <= 0)
		*transp = 0;
	if (*refl >= 1)
		*refl = 1;
}

float   computeReflection(float normalDotLight, float3 objNormal, \
float3 *lightV, __global t_cl_object *object, float3 dir) {
	if (object->specular <= 0)
		return (0);
	float3 lightRef = GET_REFL_RAY(objNormal, *lightV, normalDotLight);
	float refDotToCam = dot(lightRef, dir);
	if (refDotToCam > 0)
		return (pown(refDotToCam / (length(lightRef) * length(dir)), object->specular));
}

int notOnLim(__global t_cl_object *object, float3 *rayStart, float3 *dir, float minT) {
		float3 pointOnObj = GET_POINT_ON_RAY(minT, *dir, *rayStart);

		return (dot(object->dir, pointOnObj - object->centre) < 0 || dot(object->dir, pointOnObj - object->centre1) > 0);
}

int  setMinT(float t, t_cl_inter *inter, float start, float end, float3 *dir, \
												__global t_cl_object *object, t_cl_scene *scene) {
	if (t >= start && t < inter->minT && t < end) {
		inter->minT = t;
		inter->object = object;
		return (1);
	}
	return (0);
}

int    pointInCap(float t, t_cl_inter *inter, float start, float end, float3 *dir, \
												__global t_cl_object *object, float radius, float3 centre) {
	return (length(inter->rayStart + t * (*dir) - centre) < radius);
}

void   copyTwoVectorSubToFirst(float3 *first, float3 *second, __global float3 *third) {
		first->x = second->x - third->x;
		first->y = second->y - third->y;
		first->z = second->z - third->z;
}

int     sameSide(float3 *p1, float3 *p2, float3 *a, float3 *b) {
	float3 diff = *b - *a;
	return (dot(cross(diff, *p1 - *a), cross(diff, *p2 - *a)) >= 0);
}

int     pointInTriangle(float3 p, float3 a, float3 b, float3 c) {
	return (sameSide(&p, &a, &b, &c) && sameSide(&p, &b, &a, &c) \
			&& sameSide(&p, &c, &a, &b));
}

void  closestInter(t_cl_inter *inter, t_cl_scene *scene, float3 *rayStart, float3 *dir, float start, float end)
{
	inter->minT = FLT_MAX;
	float2 					eqRes;
	float3                  abc;
	float3                  toCenter;
	float sc;

	inter->rayStart = *rayStart;
	for(int i = 0; i < scene->objCnt; i++)
	{
		switch (scene->objects[i].type) {
			case SPHERE:
				copyTwoVectorSubToFirst(&toCenter, rayStart, &scene->objects[i].centre);
				interSphere(&abc, dir, scene->objects + i, &toCenter);
				break;
			case PLANE:
				interPlane(&abc, rayStart, dir, scene->objects + i);
				break;
			case CYLINDER:
				copyTwoVectorSubToFirst(&toCenter, rayStart, &scene->objects[i].centre);
				interCylinder(&abc, rayStart, dir, scene->objects + i, &toCenter);
				break ;
			case CONE:
				copyTwoVectorSubToFirst(&toCenter, rayStart, &scene->objects[i].centre);
				interCone(&abc, rayStart, dir, scene->objects + i, &toCenter);
				break ;
			default:
				continue;
		}
		solveEq(&abc, &eqRes);
		if (!scene->objects[i].limited) {
			if (setMinT(eqRes.x, inter, start, end, dir, scene->objects + i, scene))
				inter->cap = 0;
			if (setMinT(eqRes.y, inter, start, end, dir, scene->objects + i, scene))
				inter->cap = 0;
		}
		else  {
			if (scene->objects[i].type == CYLINDER || scene->objects[i].type == CONE) {
				if (!notOnLim(&scene->objects[i], rayStart, dir, eqRes.x)) {
					if (setMinT(eqRes.x, inter, start, end, dir, scene->objects + i, scene))
						inter->cap = 0;
				}
				if (!notOnLim(&scene->objects[i], rayStart, dir, eqRes.y)) {
					if (setMinT(eqRes.y, inter, start, end, dir, scene->objects + i, scene))
						inter->cap = 0;
				}

			}

			if (scene->objects[i].type == CYLINDER) {
				interPlaneByPointAndDir(&abc, rayStart, dir, scene->objects[i].centre, -scene->objects[i].dir);
				solveEq(&abc, &eqRes);
				if (pointInCap(eqRes.x, inter, start, end, dir, scene->objects + i, scene->objects[i].radius, scene->objects[i].centre)) {
					if (setMinT(eqRes.x, inter, start, end, dir, scene->objects + i, scene))
						inter->cap = -1;
				}
			}
			if (scene->objects[i].type == CYLINDER || scene->objects[i].type == CONE) {
				interPlaneByPointAndDir(&abc, rayStart, dir, scene->objects[i].centre1, scene->objects[i].dir);
				solveEq(&abc, &eqRes);
				if (pointInCap(eqRes.x, inter, start, end, dir, scene->objects + i, scene->objects[i].radius, scene->objects[i].centre1)) {
					if (setMinT(eqRes.x, inter, start, end, dir, scene->objects + i, scene))
						inter->cap = 1;
				}
			}
		   if (scene->objects[i].type == PLANE && eqRes.x < inter->minT) {
				if (pointInTriangle(GET_POINT_ON_RAY(eqRes.x, *dir, *rayStart), scene->objects[i].centre, scene->objects[i].centre1, scene->objects[i].centre2))
					if (setMinT(eqRes.x, inter, start, end, dir, scene->objects + i, scene))
						inter->cap = 0;
			}
		}

	}
}

void        setBias(float3 *bias, float minT, float3 *objNormal, float *begin) {
	if (minT< 100)
		(*begin) = (minT * 0.001f);
	else if (minT < 500)
		(*begin) = (minT * 0.01f);
	else if (minT < 1000)
		(*begin) = (minT * 0.1f);
	else if (minT < 5000)
		(*begin) = (minT * 0.5);
	else
		(*begin) = minT * 0.75;

	if (objNormal) {
		bias->x = objNormal->x * (*begin);
		bias->y = objNormal->y * (*begin);
		bias->z = objNormal->z * (*begin);
	}

}

float3 texture_color(float3 p, float3 p_c, t_cl_scene *scene, int type, float3 oldcolor, t_cl_inter *inter, int *pixel){
	float3 color = 0xff;
	int w = 512;
	int h = 512;
	float x = 0;
	float y = 0;
	__global int *newtexture;

	if (inter->object->texture == 0 || scene->filters->gradient)
		color = scene->filters->gradient ? (1 + inter->objNormal) * 255 : oldcolor;
	else {
		if (inter->object->texture == 1){
			newtexture = scene->earth;
		}else if (inter->object->texture == 2){
			newtexture = scene->iron;
		}else if (inter->object->texture == 3){
			newtexture = scene->stone;
		}else if (inter->object->texture == 4){
			newtexture = scene->perlin;
		}else if (inter->object->texture == 5){
			newtexture = scene->sun;
		}else if (inter->object->texture == 6){
			newtexture = scene->merc;
		}else if (inter->object->texture == 7){
			newtexture = scene->mars;
		}else if (inter->object->texture == 8){
			newtexture = scene->neptune;
		}
		if (type == 0) {
			float u = 0.5f + atan2(p.z, p.x) / (2 * M_PI);
			float v = 0.5f - 2.0f * (asin(p.y) / (2 * M_PI));
			float x = (int) (w * u) % w;
			float y = (int) (h * v) % h;

			color.z = newtexture[(int) (y * w + x)] & 0xff;
			color.y = (newtexture[(int) (y * w + x)] >> 8) & 0xff;
			color.x = newtexture[(int) (y * w + x)] >> 16;
			(*pixel) = y * w + x;
		} else if (type == 1) {
			float3
			buf_u = cross(p, (float3)(0.f, 1.f, 0.f));
			if (fabs(fast_length(buf_u)) < 0.0001f)
				buf_u = cross(p, (float3)(0.f, 0.f, 1.f));
			float3
			buf_v = cross(p, buf_u);
			float u = dot(buf_u, p_c);
			float v = dot(buf_v, p_c);
			x = (int) (w * u / inter->object->texture_size) % w;
			y = (int) (h * v / inter->object->texture_size) % h;
			if (x < 0)
				x += w;
			if (y < 0)
				y += h;
			color.z = newtexture[(int) (y * w + x)] & 0xff;
			color.y = (newtexture[(int) (y * w + x)] >> 8) & 0xff;
			color.x = newtexture[(int) (y * w + x)] >> 16;
			(*pixel) = y * w + x;
		} else if (type == 3) {
			float u = atan2(dot(inter->object->normal1, p), -dot(p, inter->object->normal2));

			float v = fast_length(inter->object->centre - p_c);
			v *= cos(atan(inter->object->sq_cos));

			p = p * v;

			v = fast_length((p + p_c) - inter->object->centre);
			x = (int) (w * u * (fabs(dot(p_c, inter->object->dir)) + inter->object->texture_size) / 100) % w;
			y = (int) (h * v * (fabs(dot(p_c, inter->object->dir)) + inter->object->texture_size) / 100) % h;
			if (x < 0)
				x += w;
			if (y < 0)
				y += h;

			color.z = newtexture[(int) (y * w + x)] & 0xff;
			color.y = (newtexture[(int) (y * w + x)] >> 8) & 0xff;
			color.x = newtexture[(int) (y * w + x)] >> 16;
			(*pixel) = y * w + x;
		} else if (type == 2) {
			float u = atan2(dot(p, inter->object->normal1), -dot(p, inter->object->normal2));
			p *= inter->object->radius;
			float v = fast_length(dot(p_c, inter->object->dir) * inter->object->dir);
			x = (int) (w * u / inter->object->texture_size) % w;
			y = (int) (h * v / inter->object->texture_size) % h;
			if (x < 0)
				x += w;
			if (y < 0)
				y += h;
			color.z = newtexture[(int) (y * w + x)] & 0xff;
			color.y = (newtexture[(int) (y * w + x)] >> 8) & 0xff;
			color.x = newtexture[(int) (y * w + x)] >> 16;
			(*pixel) = y * w + x;
		}
	}
	return (color);
}



float3  getCylinderNormal(__global t_cl_object *object, float3 *pointOnObj, int cap) {
	if (cap) {
		return (cap * object->dir);
	}
	float3 creature = *pointOnObj - object->centre;
	return (normalize(creature - object->dir * dot(creature, object->dir)));
}

float3  computeTangent(float3 *pointOnObj, __global t_cl_object *object, float sc) {
	float3 newC = GET_POINT_ON_RAY(sc, object->dir, object->centre);
	return (cross(*pointOnObj - newC, object->dir));
}

float3  getConeNormal(__global t_cl_object *object, float3 *pointOnObj, int cap) {

	float3 creature;
	float3 tangent;
	float  sc;

	if (cap)
		return (object->dir);
	creature = *pointOnObj - object->centre;
	sc = dot(creature, object->dir);
	float one = sc < 0 ? -1 : 1;
	tangent = computeTangent(pointOnObj, object, sc);
	return (one * normalize(cross(creature, tangent)));
}

void 		getNormal(t_cl_inter *inter) {
	switch (inter->object->type)
	{
		case SPHERE:
			inter->objNormal = normalize(inter->pointOnObj - inter->object->centre);
			break ;
		case PLANE:
			inter->objNormal = inter->object->dir;
			break ;
		case CYLINDER:
			inter->objNormal = getCylinderNormal(inter->object, &inter->pointOnObj, inter->cap);
			break ;
		case CONE:
			inter->objNormal = getConeNormal(inter->object, &inter->pointOnObj, inter->cap);
			break ;
		default:
			break ;
	}
}

void    computeShadow(t_cl_scene *scene, float3 pointOnObj, float3 *lightV, float shadowEnd, float3 *shadow) {
	t_cl_inter newInter;
	float3		objColor;
	int 		pixel;

	shadow->x = 0;
	shadow->y = 0;
	shadow->z = 0;
	do {
		newInter.object = 0;
		closestInter(&newInter, scene, &pointOnObj, lightV, SHADOW_EPS, shadowEnd);
		if (newInter.object != 0) {
			if (newInter.object->transp < EPS || length(*shadow) >= 1.6)
			{
				shadow->x = 1;
				shadow->y = 1;
				shadow->z = 1;
				return ;
			}

			pointOnObj = GET_POINT_ON_RAY(newInter.minT, *lightV, pointOnObj);
			newInter.pointOnObj = pointOnObj;
			getNormal(&newInter);
			objColor = texture_color(newInter.objNormal, newInter.pointOnObj, scene, newInter.object->type, newInter.object->color, &newInter, &pixel);
			shadow->x += (1.0f - newInter.object->transp) * (1 - objColor.x / 255.0f) / 4.f;
			shadow->y += (1.0f - newInter.object->transp) * (1 - objColor.y / 255.0f) / 4.f;
			shadow->z += (1.0f - newInter.object->transp) * (1 - objColor.z / 255.0f) / 4.f;
		}
	} while (newInter.object);
}

void      multOnScLocal(float3 *toMult, float sc) {
	toMult->x *= sc;
	toMult->y *= sc;
	toMult->z *= sc;
}

void    copyToFirst(float3 *first, float3 *second) {
	first->x = second->x;
	first->y = second->y;
	first->z = second->z;
}

void    addToFirst(float3 *first, float3 *second) {
	first->x += second->x;
	first->y += second->y;
	first->z += second->z;
}

void    addToFirstSc(float3 *first, float3 *second, float sc) {
	first->x += sc * second->x;
	first->y += sc * second->y;
	first->z += sc * second->z;
}

float3			get_new_normal(t_cl_scene *scene, int i, float3 oldnorm, t_cl_inter *inter)
{
	float3 new;
	float3 let;
	__global int *tmp = 0;

	if(inter->object->texture == 0) {
		return (oldnorm);
	}else if (inter->object->texture == 1){
		tmp = scene->earth_normal;
	}else if (inter->object->texture == 2){
		tmp = scene->iron_normal;
	}else if (inter->object->texture == 3){
		tmp = scene->stone_normal;
	} else if (inter->object->texture == 5){
	    return (oldnorm * -1);
	}
	new.x = tmp[i + 2] >> 16 & 255;
	new.y = (tmp[i + 1] >> 8 & 255);
	new.z = (tmp[i] & 255);
	if (new.y < 129)
		new.y = 128;
	return (normalize((new + oldnorm) / 2));
}



float3    computeColor(t_cl_inter *inter, t_cl_scene *scene) {
	int pixel;
	float3 color;

	color = texture_color(inter->objNormal, inter->pointOnObj, scene, inter->object->type, inter->object->color, inter, &pixel);
	if (inter->object->normal_map == 1)
	   inter->objNormal = get_new_normal(scene, pixel, inter->objNormal, inter);
	float3 lightV;
	float   lightLen;
	float3  intens = {0,0,0};
	float  normalDotLight;
	float  shadowEnd = 1;

	float3  shadow;

	for (int i = 0; i < scene->lightCnt; i++) {
		float3  localIntens = scene->lights[i].intens;
		if (scene->lights[i].type == AMBIENT) {
			addToFirst(&intens, &localIntens);
		}
		else
		{
			if (scene->lights[i].type == POINT || scene->lights[i].type == PARAL) {
				shadowEnd = 1;
				lightV.x = scene->lights[i].centre.x - inter->pointOnObj.x;
				lightV.y = scene->lights[i].centre.y - inter->pointOnObj.y;
				lightV.z = scene->lights[i].centre.z - inter->pointOnObj.z;
			}
			else if (scene->lights[i].type == DIRECT) {
				shadowEnd = FLT_MAX;
				lightV.x = -scene->lights[i].dir.x;
				lightV.y = -scene->lights[i].dir.y;
				lightV.z = -scene->lights[i].dir.z;
			}
			if (scene->lights[i].type == PARAL) {
				if (-dot(normalize(lightV), scene->lights[i].dir) < scene->lights[i].cosA)
					continue ;
			}
			if (scene->shadow) {
				computeShadow(scene, inter->pointOnObj, &lightV, shadowEnd, &shadow);
				if (length(shadow) >= 1.6f)
					continue ;
				localIntens.x *= 1 - shadow.x;
				localIntens.y *= 1 - shadow.y;
				localIntens.z *= 1 - shadow.z;
			}
			normalDotLight = dot(inter->objNormal, lightV);

			if (normalDotLight > 0) {
			
				lightLen = length(lightV);
			   if (lightLen > 0.00001) {
					multOnScLocal(&localIntens, 1 / (0.5 + 0.001 * lightLen + 0.0001 * lightLen * lightLen));
					addToFirstSc(&intens, &localIntens, (normalDotLight / lightLen));
					if (inter->object->specular > -1)
						addToFirstSc(&intens, &localIntens, \
							computeReflection(normalDotLight, inter->objNormal, &lightV, inter->object, inter->rayStart - inter->pointOnObj));
				}
				else {
					addToFirst(&intens, &localIntens);
				}
			}
		}
	}
	color.x *= intens.x;
	color.y *= intens.y;
	color.z *= intens.z;
	if (color.x >= 255)
		color.x = 255;
	if (color.y >= 255)
		color.y = 255;
	if (color.z >= 255)
		color.z = 255;
	return (color);
}

void    copy_state(t_traceState *where, t_traceState *from) {
	where->frac = from->frac;
	where->ray = from->ray;
	where->refl = from->refl;
	where->transp = from->transp;
	where->negDot = from->negDot;
	where->inter.cap = from->inter.cap;
	where->inter.minT = from->inter.minT;
	where->inter.pointOnObj = from->inter.pointOnObj;
	where->inter.objNormal = from->inter.objNormal;
	where->inter.rayStart = from->inter.rayStart;
	where->inter.object = from->inter.object;
}

unsigned int rayTrace(float3 rayDir, t_cl_scene *scene, int checkClick,  __global int   *closest)
{
	t_traceState    stack[5];
	t_traceState    state;
	t_traceState    *current;

	float3          finalColor = {0,0,0};
	int             rayNum = -1;

	int             deep = 0;
	float3          bias = 0;

	state.frac = 1;
	state.ray = rayDir;
	state.inter.object = 0;
	closestInter(&state.inter, scene, scene->cam, &state.ray, 0, FLT_MAX);

	current = &state;

	if (checkClick && state.inter.object)
		*closest = state.inter.object - scene->objects;
	while (current || rayNum > -1) {

		while (current && current->inter.object) {
			rayNum++;
			current->inter.pointOnObj = GET_POINT_ON_RAY(current->inter.minT, current->ray, current->inter.rayStart);
			getNormal(&current->inter);
			current->refl = current->inter.object->refl;
			current->transp = current->inter.object->transp;

			if (current->transp > EPS) {
				current->negDot = CLIP(-dot(current->ray, current->inter.objNormal));

				fresnel(&current->refl, &current->transp, current->inter.object->refr,
						current->negDot);
			}

			copy_state(&stack[rayNum], current);

			if (current->refl > EPS && rayNum < 4 && current->frac > 0.05) {

				if (current->transp < EPS)
					current->negDot = -dot(current->ray, current->inter.objNormal);
				state.frac = current->frac * current->refl;
				state.ray = GET_REFL_RAY(current->inter.objNormal, current->ray,
									   current->negDot);
				state.inter.object = 0;

				closestInter(&state.inter, scene, &current->inter.pointOnObj, &state.ray, FIND_EPS(current->inter.minT), FLT_MAX);
				current = &state;


				if (deep > 100)
					break;
				deep++;
			}
			else
				current = 0;
		}

		current = &stack[rayNum];
		rayNum--;

		if (current->inter.object) {
			finalColor += (1 - current->inter.object->refl - current->inter.object->transp) *
						  computeColor(&current->inter, scene) * current->frac;

			if (current->transp > EPS && current->frac > 0.05 && rayNum < 4) {

				state.frac = current->frac * current->transp;
				state.ray = getRefrRay(&current->inter.objNormal, current->inter.object->refr, &current->ray,
									   current->negDot);
				state.inter.object = 0;

				closestInter(&state.inter, scene, &current->inter.pointOnObj, &state.ray, FIND_EPS(current->inter.minT), FLT_MAX);
				current = &state;

			}
			else
				current = 0;
		}
		else
			current = 0;
		deep++;
		if (deep > 100)
			break;
	}

	return (colorToInt(finalColor, scene));
}

__kernel void 				test
		(
		   __global t_cl_object		*objects,
		   __global int	*output,
		   int						objCnt,
		   float3					cam,
			__global t_cl_light     *lights,
			int                     lightCnt,
			int                     shadow,
			__global float3         *transp_rotate_matrix,
			int width,
			int height,
			__global int            *earth,
			__global int            *earth_normal,
			__global int            *iron,
			__global int            *iron_normal,
			__global int            *stone,
			__global int            *stone_normal,
			__global int            *perlin,
			__global int            *closest,
			__global t_filters_on   *filters,
			int                     mouse_x,
			int                     mouse_y,
			__global int            *sun,
			__global int            *merc,
			__global int            *mars,
			__global int            *neptune
		)
{

	int i = get_global_id(0);
	int j = get_global_id(1);

	t_cl_scene scene;
	scene.filters = filters;
	scene.objects = objects;
	scene.lights = lights;
	scene.objCnt = objCnt;
	scene.lightCnt = lightCnt;
	scene.cam = &cam;
	scene.shadow = shadow;
	scene.earth = earth;
	scene.iron = iron;
	scene.iron_normal = iron_normal;
	scene.earth_normal = earth_normal;
	scene.stone = stone;
	scene.stone_normal = stone_normal;
	scene.perlin = perlin;
	scene.sun = sun;
	scene.merc = merc;
	scene.mars = mars;
	scene.neptune = neptune;

	if (i == mouse_x && j == mouse_y) {
		output[j * width + i] = rayTrace(toViewport(i, j, transp_rotate_matrix, width, height), &scene, 1, closest);
	}
	else {
		output[j * width + i] = rayTrace(toViewport(i, j, transp_rotate_matrix, width, height), &scene, 0, closest);
	}
}

